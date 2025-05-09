#include "sem_utils.hpp"
#include <stdexcept>


ExprInfo* concatStringResult(const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno) {
    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_String), lhs.isConst && rhs.isConst);

    if (result->isConst) {
        result->setString(lhs.getString() + rhs.getString());
    }
    return result;
}

/*───────── numeric (+ - * / %) ─────────*/
ExprInfo* numericOpResult(NumOp op, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno){
    BaseKind b1=lhs.type->base, b2=rhs.type->base;

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("numeric type mismatch " + baseKindToStr(b1) + numOpToStr(op) + baseKindToStr(b2), lineno);
    }

    if(op==OPMOD && (b1!=BK_Int||b2!=BK_Int)){
        SemanticError("modulus type must be int but got " + baseKindToStr(b1) + numOpToStr(op) + baseKindToStr(b2), lineno);
    }

    if((op==OPDIV||op==OPMOD) && rhs.isZeroValue()){
        if (op==OPDIV) {
            SemanticError("division by zero", lineno);
        } else {
            SemanticError("modulus by zero", lineno);
        }
    }

    BaseKind resultBase = promote(b1, b2);
    bool isConst = lhs.isConst && rhs.isConst;
    ExprInfo* result = new ExprInfo(pool.make(resultBase), isConst);

    if (isConvertible(b1, resultBase)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b1).c_str(), baseKindToStr(resultBase).c_str(), lineno);
    }
    if (isConvertible(b2, resultBase)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b2).c_str(), baseKindToStr(resultBase).c_str(), lineno);
    }

    if(isConst){
        if(resultBase==BK_Float){
            float a=toFloat(lhs), b=toFloat(rhs);
            float r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                      (op==OPMUL)?a*b : (op==OPDIV)?a/b : a; // no mod
            result->setFloat(r);
        }else if(resultBase==BK_Double){
            double a=toDouble(lhs), b=toDouble(rhs);
            double r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                       (op==OPMUL)?a*b : (op==OPDIV)?a/b : a; // no mod
            result->setDouble(r);
        }else if(resultBase==BK_Int){
            int a=lhs.getInt(), b=rhs.getInt();
            int r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                    (op==OPMUL)?a*b : (op==OPDIV)?a/b : a%b;
            result->setInt(r);
        }
    }

    return result;
}

/*───────── relational (< <= > >=) ─────────*/
ExprInfo* relOpResult(RelOp op, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno) {
    BaseKind b1=lhs.type->base, b2=rhs.type->base;

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("relational type mismatch " + baseKindToStr(b1) + relOpToStr(op) + baseKindToStr(b2), lineno);
    }

    BaseKind resultBase = promote(b1, b2);
    bool isConst = lhs.isConst && rhs.isConst;
    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), isConst);

    if (isConvertible(b1, resultBase)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b1).c_str(), baseKindToStr(resultBase).c_str(), lineno);
    }
    if (isConvertible(b2, resultBase)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b2).c_str(), baseKindToStr(resultBase).c_str(), lineno);
    }

    if(isConst){
        if(resultBase==BK_Float){
            float a=toFloat(lhs), b=toFloat(rhs);
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            result->setBool(r);
        }else if(resultBase==BK_Double){
            double a=toDouble(lhs), b=toDouble(rhs);
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            result->setBool(r);
        }else if(resultBase==BK_Int){
            int a=lhs.getInt(), b=rhs.getInt();
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            result->setBool(r);
        }
    }

    return result;
}

/*───────── equal / not‑equal ─────────*/
ExprInfo* eqOpResult(bool equal, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno) {
    BaseKind b1=lhs.type->base, b2=rhs.type->base;

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("equal type mismatch " + baseKindToStr(b1) + (equal?"==":"!=") + baseKindToStr(b2), lineno);
    }

    bool isConst = lhs.isConst && rhs.isConst;
    BaseKind resultBase = promote(b1, b2);
    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), isConst);
    
    if (isConvertible(b1, resultBase)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b1).c_str(), baseKindToStr(resultBase).c_str(), lineno);
    }
    if (isConvertible(b2, resultBase)){
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(b2).c_str(), baseKindToStr(resultBase).c_str(), lineno);
    }
    auto cmp=[&](auto a,auto b){return equal? a==b : a!=b;};

    if(isConst){
        switch(resultBase){
            case BK_Bool:   result->setBool(cmp(lhs.getBool(),   rhs.getBool())); break;
            case BK_String: result->setBool(cmp(lhs.getString(), rhs.getString())); break;
            case BK_Int:    result->setBool(cmp(lhs.getInt(),    rhs.getInt())); break;
            case BK_Float:  result->setBool(cmp(lhs.getFloat(),  rhs.getFloat())); break;
            default:        break;
        }
    }

    return result;
}

/*───────── and / or ─────────*/
ExprInfo* boolOpResult(bool isAnd, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno) {
    if (!lhs.type->isScalar() || lhs.type->base != BK_Bool) {
        SemanticError("left operand must be bool scalar", lineno);
    }

    if (!rhs.type->isScalar() || rhs.type->base != BK_Bool) {
        SemanticError("right operand must be bool scalar", lineno);
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), lhs.isConst && rhs.isConst);
    if (result->isConst) {
        result->setBool(isAnd ? (lhs.getBool() && rhs.getBool()): (lhs.getBool() || rhs.getBool()));
    }

    return result;
}

/*───────── not ─────────*/
ExprInfo* notOpResult(const ExprInfo& expr, TypeArena& pool, int lineno) {
    if (!expr.type->isScalar() || expr.type->base != BK_Bool) {
        SemanticError("operand must be bool scalar", lineno);
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), expr.isConst);
    if (expr.isConst)
        result->setBool(!expr.getBool());

    return result;
}

/*───────── unary + / - ─────────*/
ExprInfo* unaryOpResult(bool isMinus, const ExprInfo& expr, int lineno) {
    if (!expr.type->isScalar()){
        SemanticError("unary op on non-scalar type", lineno);
    }

    if (expr.type->base != BK_Int && expr.type->base != BK_Float && expr.type->base != BK_Double){
        SemanticError("unary op on non-numeric type", lineno);
    }

    ExprInfo* result = new ExprInfo(expr.type, expr.isConst);
    if (expr.isConst) {
        switch (expr.valueKind) {
            case VK_Int:
                result->setInt(isMinus ? -expr.getInt() : expr.getInt());
                break;
            case VK_Float:
                result->setFloat(isMinus ? -expr.getFloat() : expr.getFloat());
                break;
            case VK_Double:
                result->setDouble(isMinus ? -expr.getDouble() : expr.getDouble());
                break;
            default:
                SemanticError("unsupported unary constant type", lineno);
        }
    }
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

void declareFunction(const std::string& name, Type* returnType, const std::vector<Symbol>& paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno) {
    std::vector<Type*> paramTypes;
    for (auto& param : paramSyms) {
        paramTypes.push_back(param.type);
    }

    Type* funcType = typePool.makeFunc(returnType, paramTypes);
    Symbol funcSym(name, funcType, false);

    if (!symTab.insert(funcSym)) {
        SemanticError("redeclared func: " + name, lineno);
    }

    symTab.enterScope();

    
    for (auto& param : paramSyms) {
        if (!symTab.insert(param)) {
            SemanticError("redeclared param: " + param.name, lineno);
        }
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

void checkBoolExpr(const ExprInfo& expr, const std::string& context, int lineno) {
    if (expr.type->isArray()) {
        SemanticError(context + " cannot be applied to array", lineno);
    }

    if (expr.type->isFunc()) {
        SemanticError(context + " cannot be applied to function", lineno);
    }

    if (expr.type->base != BK_Bool) {
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

void checkFuncCall(Symbol* symbol, const std::string& name, const std::vector<ExprInfo>& args, int lineno) {
    if (!symbol) {
        SemanticError("undeclared function: " + name, lineno);
    }

    if (!symbol->type->isFunc()) {
        SemanticError("not a function: " + name, lineno);
    }

    size_t argCount = args.size();
    size_t expected = symbol->type->params.size();

    if (argCount != expected) {
        SemanticError("function '" + name + "' expects " +
            std::to_string(expected) + " arguments, but got " +
            std::to_string(argCount), lineno);
    }

    if (!args.empty()) {
        for (size_t i = 0; i < argCount; ++i) {
            const ExprInfo& arg = args.at(i);

            if (!arg.type->isCompatibleWith(*symbol->type->params[i])) {
                SemanticError("argument type mismatch", lineno);
            }

            if (isConvertible(arg.type->base, symbol->type->params[i]->base)) {
                printf("Warning: implicit conversion from %s to %s @ %d\n",
                    baseKindToStr(arg.type->base).c_str(),
                    baseKindToStr(symbol->type->params[i]->base).c_str(), lineno);
            }
            
        }
    }
}
