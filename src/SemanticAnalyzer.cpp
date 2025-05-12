#include "SemanticAnalyzer.hpp"
#include <stdexcept>
#include <algorithm> 

// convert ExprInfo to basic types
int toInt(const ExprInfo e){
    return (e.valueKind==VK_Int)? e.getInt() : (e.valueKind==VK_Float)? static_cast<int>(e.getFloat()) : (e.valueKind==VK_Double)? static_cast<int>(e.getDouble()) : 0;
}
float toFloat(const ExprInfo e){
    return (e.valueKind==VK_Float)? e.getFloat() : (e.valueKind==VK_Double)? e.getDouble() : (e.valueKind==VK_Int)? e.getInt() : 0.0f;
}
double toDouble(const ExprInfo e){
    return (e.valueKind==VK_Double)? e.getDouble() : (e.valueKind==VK_Float)? e.getFloat() : (e.valueKind==VK_Int)? e.getInt() : 0.0;
}
bool toBool(const ExprInfo e){
    return (e.valueKind==VK_Bool)? e.getBool() : (e.valueKind==VK_Int)? e.getInt() : (e.valueKind==VK_Float)? static_cast<int>(e.getFloat()) : (e.valueKind==VK_Double)? static_cast<int>(e.getDouble()) : false;
}
std::string toString(const ExprInfo e){
    return (e.valueKind==VK_String)? e.getString() : (e.valueKind==VK_Int)? std::to_string(e.getInt()) : (e.valueKind==VK_Float)? std::to_string(e.getFloat()) : (e.valueKind==VK_Double)? std::to_string(e.getDouble()) : "";
}

/*───────── Type Compatibility ─────────*/
std::string numOpToStr(NumOp op) {
    switch (op) {
        case OPADD: return " + ";
        case OPSUB: return " - ";
        case OPMUL: return " * ";
        case OPDIV: return " / ";
        case OPMOD: return " % ";
        default: return "unknown";
    }
}

std::string relOpToStr(RelOp op) {
    switch (op) {
        case OPLT: return " < ";
        case OPLE: return " <= ";
        case OPGT: return " > ";
        case OPGE: return " >= ";
        default: return "unknown";
    }
}

/*───────── String Concatenation ─────────*/
ExprInfo* concatStringResult(const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno) {
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }
    
    if(!lhs.type->isScalar()){
        SemanticError("left operand must be string scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be string scalar", lineno);
        return makeInvalidExpr();
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
    if(!lhs.isValid || !rhs.isValid){
        return makeInvalidExpr();
    }

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("numeric type mismatch " + baseKindToStr(b1) + numOpToStr(op) + baseKindToStr(b2), lineno);
        return makeInvalidExpr();
    }

    if(op==OPMOD && (b1!=BK_Int||b2!=BK_Int)){
        SemanticError("modulus type must be int but got " + baseKindToStr(b1) + numOpToStr(op) + baseKindToStr(b2), lineno);
        return makeInvalidExpr();
    }

    if((op==OPDIV||op==OPMOD) && rhs.isZeroValue()){
        if (op==OPDIV) {
            SemanticError("division by zero", lineno);
            return makeInvalidExpr();
        } else {
            SemanticError("modulus by zero", lineno);
            return makeInvalidExpr();
        }
    }

    BaseKind resultBase = promote(b1, b2);
    bool isConst = lhs.isConst && rhs.isConst;
    ExprInfo* result = new ExprInfo(pool.make(resultBase), isConst);

    if (isConvertible(b1, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b1) + " to " + baseKindToStr(resultBase), lineno);
    }
    if (isConvertible(b2, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b2) + " to " + baseKindToStr(resultBase), lineno);
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
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("relational type mismatch " + baseKindToStr(b1) + relOpToStr(op) + baseKindToStr(b2), lineno);
        return makeInvalidExpr();
    }

    BaseKind resultBase = promote(b1, b2);
    bool isConst = lhs.isConst && rhs.isConst;
    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), isConst);

    if (isConvertible(b1, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b1) + " to " + baseKindToStr(resultBase), lineno);
    }
    if (isConvertible(b2, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b2) + " to " + baseKindToStr(resultBase), lineno);
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
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("equal type mismatch " + baseKindToStr(b1) + (equal?"==":"!=") + baseKindToStr(b2), lineno);
        return makeInvalidExpr();
    }

    bool isConst = lhs.isConst && rhs.isConst;
    BaseKind resultBase = promote(b1, b2);
    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), isConst);
    
    if (isConvertible(b1, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b1) + " to " + baseKindToStr(resultBase), lineno);
    }
    if (isConvertible(b2, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b2) + " to " + baseKindToStr(resultBase), lineno);
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
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }

    if (!lhs.type->isScalar() || lhs.type->base != BK_Bool) {
        SemanticError("left operand must be bool scalar", lineno);
        return makeInvalidExpr();
    }

    if (!rhs.type->isScalar() || rhs.type->base != BK_Bool) {
        SemanticError("right operand must be bool scalar", lineno);
        return makeInvalidExpr();
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), lhs.isConst && rhs.isConst);
    if (result->isConst) {
        result->setBool(isAnd ? (lhs.getBool() && rhs.getBool()): (lhs.getBool() || rhs.getBool()));
    }

    return result;
}

/*───────── not ─────────*/
ExprInfo* notOpResult(const ExprInfo& expr, TypeArena& pool, int lineno) {
    if (!expr.isValid) {
        return makeInvalidExpr();
    }

    if (!expr.type->isScalar() || expr.type->base != BK_Bool) {
        SemanticError("operand must be bool scalar", lineno);
        return makeInvalidExpr();
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), expr.isConst);
    if (expr.isConst)
        result->setBool(!expr.getBool());

    return result;
}

/*───────── unary + / - ─────────*/
ExprInfo* unaryOpResult(bool isMinus, const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return makeInvalidExpr();
    }

    if (!expr.type->isScalar()){
        SemanticError("unary op on non-scalar type", lineno);
        return makeInvalidExpr();
    }

    if (expr.type->base != BK_Int && expr.type->base != BK_Float && expr.type->base != BK_Double){
        SemanticError("unary op on non-numeric type", lineno);
        return makeInvalidExpr();
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
                return makeInvalidExpr();
        }
    }
    return result;
}

/*───────── resolve array access ─────────*/
ExprInfo* resolveArrayAccess(const std::string& id, TypeArena& typePool, SymbolTable& symTab, const std::vector<int>& arrayIndex, int lineno) {
    Symbol* symbol = symTab.lookup(id);

    if (symbol) {
        SemanticError("undeclared identifier: " + id, lineno);
        return makeInvalidExpr();
    }

    if (!symbol->type->isArray()) {
        SemanticError("array index to non-array type: " + id, lineno);
        return makeInvalidExpr();
    }

    size_t given = arrayIndex.size();
    std::vector<int> dims = symbol->type->sizes;

    for (size_t i = 0; i < given; ++i) {
        int index = arrayIndex[i];
        int defined = symbol->type->sizes[i];

        if (index != 0 && (index < 0 || index >= defined)) {
            SemanticError(
                "array index out of bounds: " + std::to_string(index) +
                " not in [0.." + std::to_string(defined - 1) + "]",
                lineno
            );
            return makeInvalidExpr();
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
    if (!expr.isValid) {
        return;
    }

    if (expr.type->base != BK_Bool || !expr.type->isScalar()) {
        SemanticError(context + " condition must be bool scalar", lineno);
        return;
    }
}

/*───────── check is the expression a numeric scalar ─────────*/
void checkIncDecValid(const std::string& op, const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return;
    }

    if (expr.isConst){
        SemanticError(op + " cannot be applied to const", lineno);
        return;
    }

    if (expr.type->isArray()){
        SemanticError(op + " cannot be applied to array", lineno);
        return;
    }

    if (expr.type->isFunc()){
        SemanticError(op + " cannot be applied to function", lineno);
        return;
    }

    if (expr.type->base != BK_Int && expr.type->base != BK_Float && expr.type->base != BK_Double){
        SemanticError(op + " requires int/float/double, got: " + baseKindToStr(expr.type->base), lineno);
        return;
    }
}

/*───────── check foreach range ─────────*/
void checkForeachRange(const ExprInfo& from, const ExprInfo& to, int lineno) {
    if (!from.isValid || !to.isValid) {
        return;
    }

    if (from.type->base != BK_Int || !from.type->isScalar())
        SemanticError("foreach range start must be const int scalar", lineno);

    if (to.type->base != BK_Int || !to.type->isScalar())
        SemanticError("foreach range end must be const int scalar", lineno);
}

/*───────── check array index ─────────*/
int extractArrayIndexOrZero(const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return 0;
    }

    if (expr.type->base != BK_Int) {
        SemanticError("array index must be int", lineno);
        return 0;
    }

    if (expr.isConst) {
        if (expr.valueKind != VK_Int) {
            SemanticError("array index must be int", lineno);
            return 0;
        }
        return expr.getInt();
    }
    return 0;
}

/*───────── check array dimension ─────────*/
int checkArrayDimExpr(const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return -1;
    }

    if (!expr.isConst || !expr.type->isScalar() || expr.type->base != BK_Int || expr.valueKind != VK_Int) {
        SemanticError("array dimension must be const int scalar", lineno);
        return -1;
    }

    int val = expr.getInt();
    if (val <= 0){
        SemanticError("array dimension must be positive", lineno);
        return -1;
    }

    return val;
}

/*───────── check foreach index ─────────*/
void checkForeachIndex(Symbol* sym, int lineno) {
    if (!sym){
        SemanticError("undeclared foreach variable", lineno);
        return;
    }

    if (sym->type->base != BK_Int){
        SemanticError("foreach index must be int", lineno);
        return;
    }

    if (sym->isConst){
        SemanticError("foreach index cannot be const", lineno);
        return;
    }
}

/*───────── check variable declaration ─────────*/
void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno) {
    Symbol* exist = symTab.lookupGlobal(s.name);
    if (exist && exist->type->isFunc()) {
        SemanticError("variable '" + s.name + "' conflicts with function", lineno);
        return;
    }

    if (!symTab.insert(s)) {
        SemanticError("redeclared variable: " + s.name, lineno);
        return;
    }
}

/*───────── check function declaration ─────────*/
void declareFunction(const std::string& name, Type* returnType, const std::vector<Symbol>& paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno) {
    std::vector<Type*> paramTypes;
    for (auto& param : paramSyms) {
        paramTypes.push_back(param.type);
    }

    Symbol* exist = symTab.lookupGlobal(name);
    if (exist) {
        SemanticError(" '" + name + "' already declared", lineno);
    } else {
        Type* funcType = typePool.makeFunc(returnType, paramTypes);
        Symbol funcSym(name, funcType, false);

        if (!symTab.insert(funcSym)) {
            SemanticError("redeclared func: " + name, lineno);
            return;
        }
    }

    symTab.enterScope();

    
    for (auto& param : paramSyms) {
        if (!symTab.insert(param)) {
            SemanticError("redeclared param: " + param.name, lineno);
            return;
        }
    }
}

/*───────── check function call ─────────*/
bool checkFuncCall(Symbol* symbol, const std::string& name, const std::vector<ExprInfo>& args, int lineno) {
    if (!symbol) {
        SemanticError("undeclared function: " + name, lineno);
        return false;
    }

    if (!symbol->type->isFunc()) {
        SemanticError("not a function: " + name, lineno);
        return false;
    }

    size_t argCount = args.size();
    size_t expected = symbol->type->params.size();

    if (argCount != expected) {
        SemanticError("function '" + name + "' expects " +
            std::to_string(expected) + " arguments, but got " +
            std::to_string(argCount), lineno);
        return false;
    }

    if (!args.empty()) {
        for (size_t i = 0; i < argCount; ++i) {
            const ExprInfo& arg = args.at(i);
            if (!arg.isValid) {
                return false;
            }

            if (!arg.type->isCompatibleWith(*symbol->type->params[i])) {
                SemanticError("argument type mismatch", lineno);
                return false;
            }

            if (isConvertible(arg.type->base, symbol->type->params[i]->base)) {
                SemanticWarning("implicit conversion from " + baseKindToStr(arg.type->base) + " to " + baseKindToStr(symbol->type->params[i]->base), lineno);
            }
        }
    }

    return true;
}

/*───────── check assignment ─────────*/
void checkAssignment(const ExprInfo& target, const ExprInfo& value, int lineno) {
    if (!target.isValid || !value.isValid) {
        return;
    }

    if (target.type->isFunc()) {
        SemanticError("cannot assign to function", lineno);
        return;
    }

    if (target.type->isArray()) {
        SemanticError("cannot assign to array", lineno);
        return;
    }

    if (target.isConst) {
        SemanticError("cannot assign to const variable", lineno);
        return;
    }

    if (value.type->isFunc()) {
        SemanticError("cannot assign function to variable", lineno);
        return;
    }

    if (value.type->isArray()) {
        SemanticError("cannot assign array to variable", lineno);
        return;
    }

    if (isConvertible(value.type->base, target.type->base)) {
        SemanticWarning("implicit conversion from " + baseKindToStr(value.type->base) + " to " + baseKindToStr(target.type->base), lineno); 
    }
}

/*───────── check print ─────────*/
void checkPrint(const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return;
    }

    if (expr.type->isFunc()) {
        SemanticError("cannot print function", lineno);
        return;
    }

    if (expr.type->isArray()) {
        SemanticError("cannot print array", lineno);
        return;
    }

    if (expr.type->base == BK_Void) {
        SemanticError("cannot print void type", lineno);
        return;
    }
}

/*───────── check read ─────────*/
void checkRead(const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return;
    }

    if (expr.type->isFunc()) {
        SemanticError("cannot read to function", lineno);
        return;
    }

    if (expr.type->isArray()) {
        SemanticError("cannot read to array", lineno);
        return;
    }

    if (expr.type->base == BK_Void) {
        SemanticError("cannot read to void type", lineno);
        return;
    }
}

/*───────── check variable declaration ─────────*/
void tryDeclareVarable(SymbolTable& symTab, TypeArena& typePool, const VarInit& varInit, Type* type, int lineno){
    if (!varInit.isValid) {
        return;
    }

    Symbol s("", nullptr, false);

    if (varInit.constType != nullptr) {
        if (!type->isCompatibleWith(*varInit.constType)) {
            SemanticError("var type mismatch", lineno);
            return;
        }

        if(isConvertible(type->base, varInit.constType->base)) {
            SemanticWarning("implicit conversion from " + baseKindToStr(varInit.constType->base) + " to " + baseKindToStr(type->base), lineno);
        }
        s = Symbol(varInit.name, type, false);
    } 
    else if (!varInit.arrayDims.empty()) {
        Type* arrType = typePool.makeArray(type, varInit.arrayDims);
        s = Symbol(varInit.name, arrType, false);
    } 
    else {
        s = Symbol(varInit.name, type, false);
    }

    tryInsertVar(symTab, s, lineno);
    
}

/*───────── check constant declaration ─────────*/
void tryDeclareConstant(SymbolTable& symTab, std::string& id, Type* type, const ExprInfo& value, int lineno){
    if (!value.isValid) {
        return;
    }

    if (value.type->isFunc()) {
        SemanticError("cannot assign function to const", lineno);
        return;
    }

    if (value.type->isArray()) {
        SemanticError("cannot assign array to const", lineno);
        return;
    }

    if (!isBaseCompatible(type->base, value.type->base)) {
        SemanticError("const type mismatch " + baseKindToStr(type->base) + " = " + baseKindToStr(value.type->base), lineno);
        return;
    }

    if (!value.isConst) {
        SemanticError("const expression must be const", lineno);
        return;
    }

    Symbol s(id, type, true);
    s.setConstValueFromExpr(&value);

    Symbol* exist = symTab.lookupGlobal(s.name);
    if (exist && exist->type->isFunc()) {
        SemanticError("const '" + s.name + "' conflicts with function", lineno);
        return;
    }

    if (!symTab.insert(s)) {
        SemanticError("redeclared const: " + id, lineno);
        return;
    }

    if (isConvertible(type->base, value.type->base)) {
        SemanticWarning("implicit conversion from " + baseKindToStr(value.type->base) + " to " + baseKindToStr(type->base), lineno);
    }
}