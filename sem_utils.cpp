#include "sem_utils.hpp"
#include <stdexcept>

/*───────── numeric (+ - * / %) ─────────*/
ExprInfo* numericResult(NumOp op, ExprInfo* lhs, ExprInfo* rhs,
                        TypeArena& pool, int lineno)
{
    BaseKind b1=lhs->type->base, b2=rhs->type->base;
    bool isConst = lhs->isConst && rhs->isConst;

    if(!((b1==BK_Int||b1==BK_Float)&&(b2==BK_Int||b2==BK_Float)))
        throw SemanticError("numeric type mismatch", lineno);

    if(op==OPMOD && (b1!=BK_Int||b2!=BK_Int))
        throw SemanticError("modulus type mismatch", lineno);

    if((op==OPDIV||op==OPMOD) && rhs->isZeroValue())
        throw SemanticError(op==OPDIV? "division by zero":"modulus by zero", lineno);

    BaseKind res = (b1==BK_Float||b2==BK_Float)? BK_Float : BK_Int;
    ExprInfo* out=new ExprInfo(pool.make(res), isConst);

    if(isConst){
        if(res==BK_Float){
            float a=toFloat(lhs), b=toFloat(rhs);
            float r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                      (op==OPMUL)?a*b : (op==OPDIV)?a/b : a; // no mod
            out->setFloat(r);
        }else{
            int a=lhs->getInt(), b=rhs->getInt();
            int r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                    (op==OPMUL)?a*b : (op==OPDIV)?a/b : a%b;
            out->setInt(r);
        }
    }
    return out;
}

/*───────── relational (< <= > >=) ─────────*/
ExprInfo* relResult(RelOp op, ExprInfo* lhs, ExprInfo* rhs,
                    TypeArena& pool, int lineno)
{
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
ExprInfo* eqResult(bool equal, ExprInfo* l, ExprInfo* r,
                   TypeArena& pool, int lineno)
{
    BaseKind b1=l->type->base, b2=r->type->base;
    bool isConst = l->isConst && r->isConst;
    ExprInfo* out=new ExprInfo(pool.make(BK_Bool), isConst);

    auto cmp=[&](auto a,auto b){return equal? a==b : a!=b;};

    if((b1==BK_Int||b1==BK_Float)&&(b2==BK_Int||b2==BK_Float)){
        if(isConst) out->setBool(cmp(toFloat(l),toFloat(r)));
    }
    else if(b1==b2){
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
