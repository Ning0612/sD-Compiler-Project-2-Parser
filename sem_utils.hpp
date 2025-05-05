#pragma once
#include "error.hpp"
#include "expr.hpp"
#include "sd_types.hpp"
#include "symtab.hpp"

/* 小工具：安全數值轉 float / int */
inline float toFloat(const ExprInfo* e){
    return (e->valueKind==VK_Float)? e->getFloat() : e->getInt();
}
inline int   toInt  (const ExprInfo* e){ return e->getInt(); }

/* enum 列舉放在 header，函式原型 */
enum NumOp { OPADD, OPSUB, OPMUL, OPDIV, OPMOD };
enum RelOp { OPLT, OPLE, OPGT, OPGE };

ExprInfo* numericResult(NumOp op, ExprInfo* l, ExprInfo* r,
                        TypeArena& arena, int lineno);
ExprInfo* relResult    (RelOp op,  ExprInfo* l, ExprInfo* r,
                        TypeArena& arena, int lineno);
ExprInfo* eqResult     (bool equal,ExprInfo* l, ExprInfo* r,
                        TypeArena& arena, int lineno);
