#pragma once
#include "var.hpp" 
#include "error.hpp"
#include "expr.hpp"
#include "sd_types.hpp"
#include "symtab.hpp"

/* 小工具：安全數值轉 float / int */
inline float toFloat(const ExprInfo* e){
    return (e->valueKind==VK_Float)? e->getFloat() : e->getInt();
}
inline double toDouble(const ExprInfo* e){
    return (e->valueKind==VK_Double)? e->getDouble() : toFloat(e);
}
inline bool   toBool(const ExprInfo* e){
    return (e->valueKind==VK_Bool)? e->getBool() : (e->valueKind==VK_Float)? e->getFloat()!=0.0f : e->getInt()!=0;
}
inline int   toInt  (const ExprInfo* e){ 
    return e->getInt();
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
enum RelOp { OPLT, OPLE, OPGT, OPGE };

ExprInfo* numericResult(NumOp op, ExprInfo* l, ExprInfo* r, TypeArena& arena, int lineno);
ExprInfo* relResult    (RelOp op,  ExprInfo* l, ExprInfo* r, TypeArena& arena, int lineno);
ExprInfo* eqResult     (bool equal,ExprInfo* l, ExprInfo* r, TypeArena& arena, int lineno);
void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno);
void declareFunction(const std::string& name, Type* returnType, std::vector<Symbol*>* paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno);
int extractArrayIndexOrZero(ExprInfo* expr, int lineno);
void checkIncDecValid(ExprInfo* sym, const std::string& op, int lineno);
void checkBoolExpr(ExprInfo* expr, const std::string& context, int lineno);
void checkForeachRange(ExprInfo* from, ExprInfo* to, int lineno);
void checkForeachIndex(Symbol* sym, int lineno);
int checkArrayDimExpr(ExprInfo* e, int lineno);
void checkFuncCall(Symbol* symbol, const std::string& name, std::vector<ExprInfo*>* args, int lineno);