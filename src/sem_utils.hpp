#pragma once
#include "var.hpp" 
#include "error.hpp"
#include "expr.hpp"
#include "sd_types.hpp"
#include "symtab.hpp"

/* 小工具：安全數值轉 float / int */
inline int toInt(const ExprInfo e){
    return (e.valueKind==VK_Int)? e.getInt() : (e.valueKind==VK_Float)? static_cast<int>(e.getFloat()) : (e.valueKind==VK_Double)? static_cast<int>(e.getDouble()) : 0;
}
inline float toFloat(const ExprInfo e){
    return (e.valueKind==VK_Float)? e.getFloat() : (e.valueKind==VK_Double)? e.getDouble() : (e.valueKind==VK_Int)? e.getInt() : 0.0f;
}
inline double toDouble(const ExprInfo e){
    return (e.valueKind==VK_Double)? e.getDouble() : (e.valueKind==VK_Float)? e.getFloat() : (e.valueKind==VK_Int)? e.getInt() : 0.0;
}
inline bool toBool(const ExprInfo e){
    return (e.valueKind==VK_Bool)? e.getBool() : (e.valueKind==VK_Int)? e.getInt() : (e.valueKind==VK_Float)? static_cast<int>(e.getFloat()) : (e.valueKind==VK_Double)? static_cast<int>(e.getDouble()) : false;
}
inline std::string toString(const ExprInfo e){
    return (e.valueKind==VK_String)? e.getString() : (e.valueKind==VK_Int)? std::to_string(e.getInt()) : (e.valueKind==VK_Float)? std::to_string(e.getFloat()) : (e.valueKind==VK_Double)? std::to_string(e.getDouble()) : "";
}


inline std::string baseKindToStr(BaseKind kind) {
    switch (kind) {
        case BK_Int: return "int";
        case BK_Float: return "float";
        case BK_Double: return "double";
        case BK_Bool: return "bool";
        case BK_String: return "string";
        case BK_Void: return "void";
        default: return "unknown";
    }
}

bool isAssignable(Type* lhs, Type* rhs);

/* enum 列舉放在 header，函式原型 */
enum NumOp { OPADD, OPSUB, OPMUL, OPDIV, OPMOD };

inline std::string numOpToStr(NumOp op) {
    switch (op) {
        case OPADD: return "+";
        case OPSUB: return "-";
        case OPMUL: return "*";
        case OPDIV: return "/";
        case OPMOD: return "%";
        default: return "unknown";
    }
}

enum RelOp { OPLT, OPLE, OPGT, OPGE };

inline std::string relOpToStr(RelOp op) {
    switch (op) {
        case OPLT: return "<";
        case OPLE: return "<=";
        case OPGT: return ">";
        case OPGE: return ">=";
        default: return "unknown";
    }
}

ExprInfo* concatStringResult(const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);
ExprInfo* numericOpResult(NumOp op, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);
ExprInfo* relOpResult    (RelOp op,  const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);
ExprInfo* eqOpResult     (bool equal, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);
ExprInfo* boolOpResult(bool isAnd, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);
ExprInfo* notOpResult(const ExprInfo& expr, TypeArena& pool, int lineno);
ExprInfo* unaryOpResult(bool isMinus, const ExprInfo& expr, int lineno);
ExprInfo* resolveArrayAccess(const std::string& id, TypeArena& typePool, SymbolTable& symTab, const std::vector<int>& arrayIndex, int lineno);

void checkBoolExpr(const std::string& context, const ExprInfo& expr, int lineno);
void checkIncDecValid(const std::string& op, const ExprInfo& expr, int lineno);
void checkForeachRange(const ExprInfo& from, const ExprInfo& to, int lineno);
int extractArrayIndexOrZero(const ExprInfo& expr, int lineno);
int checkArrayDimExpr(const ExprInfo& expr, int lineno);

void checkForeachIndex(Symbol* sym, int lineno);
void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno);

void declareFunction(const std::string& name, Type* returnType, const std::vector<Symbol>& paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno);
void checkFuncCall(Symbol* symbol, const std::string& name, const std::vector<ExprInfo>& args, int lineno);
void checkAssignment(const ExprInfo& target, const ExprInfo& value, int lineno);
void checkPrint(const ExprInfo& expr, int lineno);
void checkRead(const ExprInfo& expr, int lineno);
void tryDeclareVarables(SymbolTable& symTab, TypeArena& typePool, std::vector<VarInit>& varInits, Type* type, int lineno);
void tryDeclareConstant(SymbolTable& symTab, std::string& id, Type* type, const ExprInfo& value, int lineno);