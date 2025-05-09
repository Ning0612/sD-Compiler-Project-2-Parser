#include "sem_utils.hpp"
#include <stdexcept>


ExprInfo* concatStringResult(const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno) {
    if(!lhs.type->isScalar()){
        throw SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        throw SemanticError("right operand must be scalar", lineno);
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
        throw SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        throw SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2))){
        throw SemanticError("numeric type mismatch " + baseKindToStr(b1) + numOpToStr(op) + baseKindToStr(b2), lineno);
    }

    if(op==OPMOD && (b1!=BK_Int||b2!=BK_Int)){
        throw SemanticError("modulus type must be int but got " + baseKindToStr(b1) + numOpToStr(op) + baseKindToStr(b2), lineno);
    }

    if((op==OPDIV||op==OPMOD) && rhs.isZeroValue()){
        if (op==OPDIV) {
            throw SemanticError("division by zero", lineno);
        } else {
            throw SemanticError("modulus by zero", lineno);
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
        throw SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        throw SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2))){
        throw SemanticError("relational type mismatch " + baseKindToStr(b1) + relOpToStr(op) + baseKindToStr(b2), lineno);
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
        throw SemanticError("left operand must be scalar", lineno);
    }

    if(!rhs.type->isScalar()){
        throw SemanticError("right operand must be scalar", lineno);
    }

    if(!(isBaseCompatible(b1, b2))){
        throw SemanticError("equal type mismatch " + baseKindToStr(b1) + (equal?"==":"!=") + baseKindToStr(b2), lineno);
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
        throw SemanticError("left operand must be bool scalar", lineno);
    }

    if (!rhs.type->isScalar() || rhs.type->base != BK_Bool) {
        throw SemanticError("right operand must be bool scalar", lineno);
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
        throw SemanticError("operand must be bool scalar", lineno);
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), expr.isConst);
    if (expr.isConst)
        result->setBool(!expr.getBool());

    return result;
}

/*───────── unary + / - ─────────*/
ExprInfo* unaryOpResult(bool isMinus, const ExprInfo& expr, int lineno) {
    if (!expr.type->isScalar()){
        throw SemanticError("unary op on non-scalar type", lineno);
    }

    if (expr.type->base != BK_Int && expr.type->base != BK_Float && expr.type->base != BK_Double){
        throw SemanticError("unary op on non-numeric type", lineno);
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
                throw SemanticError("unsupported unary constant type", lineno);
        }
    }
    return result;
}

/*───────── resolve array access ─────────*/
ExprInfo* resolveArrayAccess(const std::string& id, TypeArena& typePool, SymbolTable& symTab, const std::vector<int>& arrayIndex, int lineno) {
    Symbol* symbol = symTab.lookup(id);

    if (!symbol) {
        throw SemanticError("undeclared identifier: " + id, lineno);
        return nullptr;
    }

    if (!symbol->type->isArray()) {
        throw SemanticError("array index to non-array type: " + id, lineno);
        return nullptr;
    }

    size_t given = arrayIndex.size();
    std::vector<int> dims = symbol->type->sizes;

    for (size_t i = 0; i < given; ++i) {
        int index = arrayIndex[i];
        int defined = symbol->type->sizes[i];

        if (index != 0 && (index < 0 || index >= defined)) {
            throw SemanticError(
                "array index out of bounds: " + std::to_string(index) +
                " not in [0.." + std::to_string(defined - 1) + "]",
                lineno
            );
        }

        if (!dims.empty()) {
            dims.erase(dims.begin());
        }
    }

    Type* baseType = typePool.make(symbol->type->base);
    Type* resultType = dims.empty() ? baseType : typePool.makeArray(baseType, dims);
    return new ExprInfo(resultType, symbol->isConst);
}

/*───────── check is the expression a bool scalar ─────────*/
void checkBoolExpr(const std::string& context, const ExprInfo& expr, int lineno) {
if (expr.type->base != BK_Bool || !expr.type->isScalar()) {
        throw SemanticError(context + " condition must be bool scalar", lineno);
    }
}

/*───────── check is the expression a numeric scalar ─────────*/
void checkIncDecValid(const std::string& op, const ExprInfo& expr, int lineno) {
    if (expr.isConst)
        throw SemanticError(op + " cannot be applied to const", lineno);

    if (expr.type->isArray())
        throw SemanticError(op + " cannot be applied to array", lineno);

    if (expr.type->isFunc())
        throw SemanticError(op + " cannot be applied to function", lineno);

    if (expr.type->base != BK_Int && expr.type->base != BK_Float && expr.type->base != BK_Double)
        throw SemanticError(op + " requires int/float/double, got: " + baseKindToStr(expr.type->base), lineno);
}

/*───────── check foreach range ─────────*/
void checkForeachRange(const ExprInfo& from, const ExprInfo& to, int lineno) {
    if (from.type->base != BK_Int || !from.isConst || !from.type->isScalar())
        throw SemanticError("foreach range start must be const int scalar", lineno);

    if (to.type->base != BK_Int || !to.isConst || !to.type->isScalar())
        throw SemanticError("foreach range end must be const int scalar", lineno);

    if (from.getInt() >= to.getInt())
        throw SemanticError("foreach range start must be less than end", lineno);
}

/*───────── check array index ─────────*/
int extractArrayIndexOrZero(const ExprInfo& expr, int lineno) {
    if (expr.type->base != BK_Int) {
        throw SemanticError("array index must be int", lineno);
    }

    if (expr.isConst) {
        if (expr.valueKind != VK_Int) {
            throw SemanticError("array index must be int", lineno);
        }
        return expr.getInt();
    }
    return 0;
}

int checkArrayDimExpr(const ExprInfo& expr, int lineno) {
    if (!expr.isConst || !expr.type->isScalar() || expr.type->base != BK_Int || expr.valueKind != VK_Int) {
        throw SemanticError("array dimension must be const int scalar", lineno);
    }

    int val = expr.getInt();
    if (val <= 0){
        throw SemanticError("array dimension must be positive", lineno);
    }

    return val;
}

void checkForeachIndex(Symbol* sym, int lineno) {
    if (!sym) 
        throw SemanticError("undeclared foreach variable", lineno);

    if (sym->type->base != BK_Int)
        throw SemanticError("foreach index must be int", lineno);
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

void declareFunction(const std::string& name, Type* returnType, const std::vector<Symbol>& paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno) {
    std::vector<Type*> paramTypes;
    for (auto& param : paramSyms) {
        paramTypes.push_back(param.type);
    }

    Type* funcType = typePool.makeFunc(returnType, paramTypes);
    Symbol funcSym(name, funcType, false);

    if (!symTab.insert(funcSym)) {
        throw SemanticError("redeclared func: " + name, lineno);
    }

    symTab.enterScope();

    
    for (auto& param : paramSyms) {
        if (!symTab.insert(param)) {
            throw SemanticError("redeclared param: " + param.name, lineno);
        }
    }
}

void checkFuncCall(Symbol* symbol, const std::string& name, const std::vector<ExprInfo>& args, int lineno) {
    if (!symbol) {
        throw SemanticError("undeclared function: " + name, lineno);
    }

    if (!symbol->type->isFunc()) {
        throw SemanticError("not a function: " + name, lineno);
    }

    size_t argCount = args.size();
    size_t expected = symbol->type->params.size();

    if (argCount != expected) {
        throw SemanticError("function '" + name + "' expects " +
            std::to_string(expected) + " arguments, but got " +
            std::to_string(argCount), lineno);
    }

    if (!args.empty()) {
        for (size_t i = 0; i < argCount; ++i) {
            const ExprInfo& arg = args.at(i);

            if (!arg.type->isCompatibleWith(*symbol->type->params[i])) {
                throw SemanticError("argument type mismatch", lineno);
            }

            if (isConvertible(arg.type->base, symbol->type->params[i]->base)) {
                printf("Warning: implicit conversion from %s to %s @ %d\n",
                    baseKindToStr(arg.type->base).c_str(),
                    baseKindToStr(symbol->type->params[i]->base).c_str(), lineno);
            }
            
        }
    }
}

void checkAssignment(const ExprInfo& target, const ExprInfo& value, int lineno) {
    if (target.type->isFunc()) {
        throw SemanticError("cannot assign to function", lineno);
    }

    if (target.type->isArray()) {
        throw SemanticError("cannot assign to array", lineno);
    }

    if (target.isConst) {
        throw SemanticError("cannot assign to const variable", lineno);
    }

    if (value.type->isFunc()) {
        throw SemanticError("cannot assign function to variable", lineno);
    }

    if (value.type->isArray()) {
        throw SemanticError("cannot assign array to variable", lineno);
    }

    if (isConvertible(value.type->base, target.type->base)) {
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr(value.type->base).c_str(), baseKindToStr(target.type->base).c_str(), lineno);
    }
}

void checkPrint(const ExprInfo& expr, int lineno) {
    if (expr.type->isFunc()) {
        throw SemanticError("cannot print function", lineno);
    }

    if (expr.type->isArray()) {
        throw SemanticError("cannot print array", lineno);
    }

    if (expr.type->base == BK_Void) {
        throw SemanticError("cannot print void type", lineno);
    }
}

void checkRead(const ExprInfo& expr, int lineno) {
    if (expr.type->isFunc()) {
        throw SemanticError("cannot read to function", lineno);
    }

    if (expr.type->isArray()) {
        throw SemanticError("cannot read to array", lineno);
    }

    if (expr.type->base == BK_Void) {
        throw SemanticError("cannot read to void type", lineno);
    }
}

void tryDeclareVarables(SymbolTable& symTab, TypeArena& typePool, std::vector<VarInit>& varInits, Type* type, int lineno){
    for (auto& var : varInits) {
        Symbol s("", nullptr, false);

        if (var.constType != nullptr) {
            if (!type->isCompatibleWith(*var.constType)) {
                throw SemanticError("var type mismatch", lineno);
            }

            if(isConvertible(type->base, var.constType->base)) {
                printf("Warning: implicit conversion from %s to %s @ line %d\n",
                    baseKindToStr(type->base).c_str(), baseKindToStr(var.constType->base).c_str(), lineno);
            }
            s = Symbol(var.name, type, false);
        } 
        else if (!var.arrayDims.empty()) {
            Type* arrType = typePool.makeArray(type, var.arrayDims);
            s = Symbol(var.name, arrType, false);
        } 
        else {
            s = Symbol(var.name, type, false);
        }

        tryInsertVar(symTab, s, lineno);
    }
}

void tryDeclareConstant(SymbolTable& symTab, std::string& id, Type* type, const ExprInfo& value, int lineno){
    if (value.type->isFunc()) {
        throw SemanticError("cannot assign function to const", lineno);
    }

    if (value.type->isArray()) {
        throw SemanticError("cannot assign array to const", lineno);
    }

    if (!isBaseCompatible(type->base, value.type->base)) {
        throw SemanticError("const type mismatch " + baseKindToStr(type->base) + " = " + baseKindToStr(value.type->base), lineno);
    }

    if (!value.isConst) {
        throw SemanticError("const expression must be const", lineno);
    }

    Symbol s(id, type, true);
    s.setConstValueFromExpr(&value);

    Symbol* exist = symTab.lookupGlobal(s.name);
    if (exist && exist->type->isFunc()) {
        throw SemanticError("const '" + s.name + "' conflicts with function", lineno);
    }

    if (!symTab.insert(s)) {
        throw SemanticError("redeclared const: " + id, lineno);
    }

    if (isConvertible(type->base, value.type->base)) {
        printf("Warning: implicit conversion from %s to %s @ line %d\n",
            baseKindToStr(type->base).c_str(), baseKindToStr(value.type->base).c_str(), lineno);
    }
}