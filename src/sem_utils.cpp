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
        SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs->type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2)))
        SemanticError("numeric type mismatch", lineno);

    if(op==OPMOD && (b1!=BK_Int||b2!=BK_Int))
        SemanticError("modulus type mismatch", lineno);

    if((op==OPDIV||op==OPMOD) && rhs->isZeroValue())
        SemanticError(op==OPDIV? "division by zero":"modulus by zero", lineno);

    BaseKind res = promote(b1, b2);
    ExprInfo* out=new ExprInfo(pool.make(res), isConst);

    if (isConvertible(b1, res)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b1).c_str(), baseKindToStr(res).c_str(), lineno);
    }

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

    if(!lhs->type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs->type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2)))
        SemanticError("numeric type mismatch", lineno);

    BaseKind res = promote(b1, b2);
    ExprInfo* out=new ExprInfo(pool.make(BK_Bool), isConst);

    if (isConvertible(b1, res)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b1).c_str(), baseKindToStr(res).c_str(), lineno);
    }
    if (isConvertible(b2, res)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b2).c_str(), baseKindToStr(res).c_str(), lineno);
    }

    if(isConst){
        if(res==BK_Float){
            float a=toFloat(lhs), b=toFloat(rhs);
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            out->setBool(r);
        }else if(res==BK_Double){
            double a=toDouble(lhs), b=toDouble(rhs);
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            out->setBool(r);
        }else if(res==BK_Int){
            int a=lhs->getInt(), b=rhs->getInt();
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            out->setBool(r);
        }
    }

    return out;
}

/*───────── equal / not‑equal ─────────*/
ExprInfo* eqResult(bool equal, ExprInfo* l, ExprInfo* r, TypeArena& pool, int lineno) {
    BaseKind b1=l->type->base, b2=r->type->base;
    BaseKind res = promote(b1, b2);
    bool isConst = l->isConst && r->isConst;

    if (l->type->isArray() || r->type->isArray()) {
        SemanticError("array comparison not supported", lineno);
    }

    if (l->type->isFunc() || r->type->isFunc()) {
        SemanticError("function comparison not supported", lineno);
    }

    ExprInfo* out=new ExprInfo(pool.make(BK_Bool), isConst);

    auto cmp=[&](auto a,auto b){return equal? a==b : a!=b;};

    if(l->type->isCompatibleWith(*r->type)){
        if(isConst){
            switch(res){
                case BK_Bool:   out->setBool(cmp(l->getBool(),   r->getBool())); break;
                case BK_String: out->setBool(cmp(l->getString(), r->getString())); break;
                case BK_Int:    out->setBool(cmp(l->getInt(),    r->getInt())); break;
                case BK_Float:  out->setBool(cmp(l->getFloat(),  r->getFloat())); break;
                default: SemanticError("unsupported ==/!= type", lineno);
            }
        }
    
    }else{
        SemanticError("equal type mismatch", lineno);
    }

    return out;
}

ExprInfo* concatString(ExprInfo* lhs, ExprInfo* rhs, TypeArena& pool) {
    ExprInfo* result = new ExprInfo(pool.make(BK_String), lhs->isConst && rhs->isConst);
    if (result->isConst) {
        result->setString(lhs->getString() + rhs->getString());
    }
    return result;
}


ExprInfo* applyUnaryOp(ExprInfo* e, bool isMinus, int lineno) {
    if (!e->type->isScalar())
        SemanticError("unary op on non-scalar type", lineno);

    if (e->type->base != BK_Int && e->type->base != BK_Float /*&& e->type->base != BK_Double*/) 
        SemanticError("unary op on non-numeric type", lineno);

    ExprInfo* expr = new ExprInfo(e->type, e->isConst);
    if (e->isConst) {
        switch (e->valueKind) {
            case VK_Int:
                expr->setInt(isMinus ? -e->getInt() : e->getInt());
                break;
            case VK_Float:
                expr->setFloat(isMinus ? -e->getFloat() : e->getFloat());
                break;
            default:
                SemanticError("unsupported unary constant type", lineno);
        }
    }
    return expr;
}

ExprInfo* evalBoolOp(const ExprInfo* lhs, const ExprInfo* rhs, bool isAnd, TypeArena& pool, int lineno) {
    if (!lhs->type->isScalar() || !rhs->type->isScalar())
        SemanticError("boolean operation on non-scalar type", lineno);
    if (lhs->type->base != BK_Bool || rhs->type->base != BK_Bool)
        SemanticError("boolean operation on non-bool type", lineno);

    ExprInfo* out = new ExprInfo(pool.make(BK_Bool), lhs->isConst && rhs->isConst);
    if (out->isConst) {
        out->setBool(isAnd ? (lhs->getBool() && rhs->getBool())
                           : (lhs->getBool() || rhs->getBool()));
    }
    return out;
}

ExprInfo* evalNot(const ExprInfo* expr, TypeArena& pool, int lineno) {
    if (!expr->type->isScalar())
        SemanticError("not on non-scalar type", lineno);
    if (expr->type->base != BK_Bool)
        SemanticError("not on non-bool type", lineno);

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), expr->isConst);
    if (expr->isConst)
        result->setBool(!expr->getBool());
    return result;
}


void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno) {
    Symbol* exist = symTab.lookupGlobal(s.name);
    if (exist && exist->type->isFunc()) {
        SemanticError("variable '" + s.name + "' conflicts with function", lineno);
    }

    if (!symTab.insert(s)) {
        SemanticError("redeclared variable: " + s.name, lineno);
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
        SemanticError("redeclared func: " + name, lineno);
    }

    symTab.enterScope();

    if (paramSyms) {
        for (auto& param : *paramSyms) {
            if (!symTab.insert(*param)) {
                SemanticError("redeclared param: " + param->name, lineno);
            }
            delete param;
        }
        delete paramSyms;
    }
}

int extractArrayIndexOrZero(ExprInfo* expr, int lineno) {
    if (expr->type->base != BK_Int) {
        SemanticError("array index must be int", lineno);
    }

    if (expr->isConst) {
        if (expr->valueKind != VK_Int) {
            SemanticError("array index must be int", lineno);
        }
        return expr->getInt();
    }
    return 0;
}

void checkIncDecValid(ExprInfo* sym, const std::string& op, int lineno) {
    if (sym->isConst)
        SemanticError(op + " cannot be applied to const", lineno);

    if (sym->type->isArray())
        SemanticError(op + " cannot be applied to array", lineno);

    if (sym->type->isFunc())
        SemanticError(op + " cannot be applied to function", lineno);

    if (sym->type->base != BK_Int && sym->type->base != BK_Float && sym->type->base != BK_Double)
        SemanticError(op + " requires int/float/double, got: " + baseKindToStr(sym->type->base), lineno);
}

void checkBoolExpr(ExprInfo* expr, const std::string& context, int lineno) {
    if (expr->type->isArray()) {
        SemanticError(context + " cannot be applied to array", lineno);
    }

    if (expr->type->isFunc()) {
        SemanticError(context + " cannot be applied to function", lineno);
    }

    if (expr->type->base != BK_Bool) {
        SemanticError(context + " condition must be bool", lineno);
    }
}

void checkForeachRange(ExprInfo* from, ExprInfo* to, int lineno) {
    if (!from->type->isScalar() || !to->type->isScalar())
        SemanticError("foreach range must be scalar", lineno);

    if (from->type->base != BK_Int || !from->isConst)
        SemanticError("foreach range must be const int", lineno);

    if (to->type->base != BK_Int || !to->isConst)
        SemanticError("foreach range must be const int", lineno);

    if (from->getInt() > to->getInt())
        SemanticError("foreach range error", lineno);
}

void checkForeachIndex(Symbol* sym, int lineno) {
    if (!sym) 
        SemanticError("undeclared foreach variable", lineno);

    if (sym->type->base != BK_Int)
        SemanticError("foreach index must be int", lineno);
}

int checkArrayDimExpr(ExprInfo* e, int lineno) {
    if (!e->isConst)
        SemanticError("array dimension must be const", lineno);

    if (e->valueKind != VK_Int)
        SemanticError("array dimension must be int", lineno);

    int val = e->getInt();
    if (val <= 0)
        SemanticError("array dimension must be positive", lineno);
    return val;
}

void checkFuncCall(Symbol* symbol, const std::string& name, std::vector<ExprInfo*>* args, int lineno) {
    if (!symbol) {
        SemanticError("undeclared function: " + name, lineno);
    }

    if (!symbol->type->isFunc()) {
        SemanticError("not a function: " + name, lineno);
    }

    size_t argCount = args ? args->size() : 0;
    size_t expected = symbol->type->params.size();

    if (argCount != expected) {
        SemanticError("function '" + name + "' expects " +
            std::to_string(expected) + " arguments, but got " +
            std::to_string(argCount), lineno);
    }

    if (args) {
        for (size_t i = 0; i < argCount; ++i) {
            if (!(*args)[i]->type->isCompatibleWith(*symbol->type->params[i])) {
                SemanticError("argument type mismatch", lineno);
            }

            if (isConvertible((*args)[i]->type->base, symbol->type->params[i]->base)) {
                printf("Warning: implicit conversion from %s to %s @ %d\n",
                    baseKindToStr((*args)[i]->type->base).c_str(),
                    baseKindToStr(symbol->type->params[i]->base).c_str(), lineno);
            }
            
            delete (*args)[i];
        }
        delete args;
    }
}
