#include "sem_utils.hpp"
#include <stdexcept>

inline bool isAssignable(Type* lhs, Type* rhs) {
    return (*lhs == *rhs);
}

/*───────── numeric (+ - * / %) ─────────*/
ExprInfo* numericResult(NumOp op, ExprInfo* lhs, ExprInfo* rhs, TypeArena& pool, int lineno) {
    BaseKind b1=lhs->type->base, b2=rhs->type->base;
    bool isConst = lhs->isConst && rhs->isConst;

    if(!lhs->type->isScalar()){
        throw SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs->type->isScalar()){
        throw SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2)))
        throw SemanticError("numeric type mismatch", lineno);

    if(op==OPMOD && (b1!=BK_Int||b2!=BK_Int))
        throw SemanticError("modulus type mismatch", lineno);

    if((op==OPDIV||op==OPMOD) && rhs->isZeroValue())
        throw SemanticError(op==OPDIV? "division by zero":"modulus by zero", lineno);

    BaseKind res = promote(b1, b2);
    ExprInfo* out=new ExprInfo(pool.make(res), isConst);

    if(isConst){
        if(res==BK_Float){
            float a=toFloat(lhs), b=toFloat(rhs);
            float r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                      (op==OPMUL)?a*b : (op==OPDIV)?a/b : a; // no mod
            out->setFloat(r);
        }else if(res==BK_Double){
            double a=toDouble(lhs), b=toDouble(rhs);
            double r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                       (op==OPMUL)?a*b : (op==OPDIV)?a/b : a; // no mod
            out->setDouble(r);
        }else if(res==BK_Int){
            int a=lhs->getInt(), b=rhs->getInt();
            int r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                    (op==OPMUL)?a*b : (op==OPDIV)?a/b : a%b;
            out->setInt(r);
        }
    }

    return out;
}

/*───────── relational (< <= > >=) ─────────*/
ExprInfo* relResult(RelOp op, ExprInfo* lhs, ExprInfo* rhs, TypeArena& pool, int lineno) {
    BaseKind b1=lhs->type->base, b2=rhs->type->base;
    bool isConst = lhs->isConst && rhs->isConst;

    if(!((b1==BK_Int||b1==BK_Float)&&(b2==BK_Int||b2==BK_Float)))
        throw SemanticError("relational type mismatch", lineno);

    ExprInfo* out=new ExprInfo(pool.make(BK_Bool), isConst);
    if(isConst){
        float a=toFloat(lhs), b=toFloat(rhs);
        bool r=(op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
        out->setBool(r);
    }
    return out;
}

/*───────── equal / not‑equal ─────────*/
ExprInfo* eqResult(bool equal, ExprInfo* l, ExprInfo* r, TypeArena& pool, int lineno) {
    BaseKind b1=l->type->base, b2=r->type->base;
    bool isConst = l->isConst && r->isConst;
    ExprInfo* out=new ExprInfo(pool.make(BK_Bool), isConst);

    auto cmp=[&](auto a,auto b){return equal? a==b : a!=b;};

    if((b1==BK_Int||b1==BK_Float)&&(b2==BK_Int||b2==BK_Float)){
        if(isConst) out->setBool(cmp(toFloat(l),toFloat(r)));
    }
    else if(l->type == r->type){
        if(isConst){
            switch(b1){
                case BK_Bool:   out->setBool(cmp(l->getBool(),   r->getBool())); break;
                case BK_String: out->setBool(cmp(l->getString(), r->getString())); break;
                case BK_Int:    out->setBool(cmp(l->getInt(),    r->getInt())); break;
                case BK_Float:  out->setBool(cmp(l->getFloat(),  r->getFloat())); break;
                default: throw SemanticError("unsupported ==/!= type", lineno);
            }
        }
    }else
        throw SemanticError("equal type mismatch", lineno);

    return out;
}

void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno) {
    Symbol* exist = symTab.lookupGlobal(s.name);
    if (exist && exist->type->isFunc()) {
        throw SemanticError("variable '" + s.name + "' conflicts with function", lineno);
    }

    if (!symTab.insert(s)) {
        throw SemanticError("redeclared variable: " + s.name, lineno);
    }
}

void declareFunction(const std::string& name, Type* returnType, std::vector<Symbol*>* paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno) {
    std::vector<Type*> paramTypes;
    if (paramSyms) {
        for (auto& param : *paramSyms) {
            paramTypes.push_back(param->type);
        }
    }

    Type* funcType = typePool.makeFunc(returnType, paramTypes);
    Symbol funcSym(name, funcType, false);

    if (!symTab.insert(funcSym)) {
        throw SemanticError("redeclared func: " + name, lineno);
    }

    symTab.enterScope();

    if (paramSyms) {
        for (auto& param : *paramSyms) {
            if (!symTab.insert(*param)) {
                throw SemanticError("redeclared param: " + param->name, lineno);
            }
            delete param;
        }
        delete paramSyms;
    }
}

int extractArrayIndexOrZero(ExprInfo* expr, int lineno) {
    if (expr->type->base != BK_Int) {
        throw SemanticError("array index must be int", lineno);
    }
    if (expr->isConst) {
        if (expr->valueKind == VK_Float) {
            throw SemanticError("array index must be int", lineno);
        }
        return expr->getInt();
    }
    return 0;
}

void checkIncDecValid(ExprInfo* sym, const std::string& op, int lineno) {
    if (sym->isConst)
        throw SemanticError(op + " cannot be applied to const", lineno);

    if (sym->type->isArray())
        throw SemanticError(op + " cannot be applied to array", lineno);

    if (sym->type->isFunc())
        throw SemanticError(op + " cannot be applied to function", lineno);

    if (sym->type->base != BK_Int && sym->type->base != BK_Float && sym->type->base != BK_Double)
        throw SemanticError(op + " requires int/float/double, got: " + baseKindToStr(sym->type->base), lineno);
}

void checkBoolExpr(ExprInfo* expr, const std::string& context, int lineno) {
    if (expr->type->isArray()) {
        throw SemanticError(context + " cannot be applied to array", lineno);
    }

    if (expr->type->isFunc()) {
        throw SemanticError(context + " cannot be applied to function", lineno);
    }

    if (expr->type->base != BK_Bool) {
        throw SemanticError(context + " condition must be bool", lineno);
    }
}

void checkForeachRange(ExprInfo* from, ExprInfo* to, int lineno) {
    if (from->type->base != BK_Int || !from->isConst)
        throw SemanticError("foreach range must be const int", lineno);

    if (to->type->base != BK_Int || !to->isConst)
        throw SemanticError("foreach range must be const int", lineno);

    if (from->getInt() > to->getInt())
        throw SemanticError("foreach range error", lineno);
}

void checkForeachIndex(Symbol* sym, int lineno) {
    if (!sym) 
        throw SemanticError("undeclared foreach variable", lineno);

    if (sym->type->base != BK_Int)
        throw SemanticError("foreach index must be int", lineno);
}

int checkArrayDimExpr(ExprInfo* e, int lineno) {
    if (!e->isConst)
        throw SemanticError("array dimension must be const", lineno);

    if (e->valueKind != VK_Int)
        throw SemanticError("array dimension must be int", lineno);

    int val = e->getInt();
    if (val <= 0)
        throw SemanticError("array dimension must be positive", lineno);
    return val;
}

void checkFuncCall(Symbol* symbol, const std::string& name, std::vector<ExprInfo*>* args, int lineno) {
    if (!symbol) {
        throw SemanticError("undeclared function: " + name, lineno);
    }

    if (!symbol->type->isFunc()) {
        throw SemanticError("not a function: " + name, lineno);
    }

    size_t argCount = args ? args->size() : 0;
    size_t expected = symbol->type->params.size();

    if (argCount != expected) {
        throw SemanticError("function '" + name + "' expects " +
            std::to_string(expected) + " arguments, but got " +
            std::to_string(argCount), lineno);
    }

    if (args) {
        for (size_t i = 0; i < argCount; ++i) {
            if (!isAssignable(symbol->type->params[i], (*args)[i]->type)) {
                throw SemanticError("argument type mismatch", lineno);
            }
            delete (*args)[i];
        }
        delete args;
    }
}
