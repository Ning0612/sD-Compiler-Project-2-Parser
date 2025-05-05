#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

/* ───── 型別系統 ───── */
enum BaseKind { BK_Int, BK_Float, BK_Bool, BK_String, BK_Void };

struct Type {
    BaseKind            base;
    int                 dim;               // 0=scalar
    std::vector<int>    sizes;             // 各維大小
    std::vector<Type*>  params;           // 函式參數型別
    Type*               ret;               // 函式回傳型別

    Type(BaseKind b) : base(b), dim(0), ret(0){}

    bool isArray() const { return dim > 0; }
    bool isFunc()  const { return ret != 0 || !params.empty(); }
    bool operator==(const Type& o) const;
    bool operator!=(const Type& o) const;
    void print() const {
        printf("Type: ");
        if (base == BK_Int) printf("int");
        else if (base == BK_Float) printf("float");
        else if (base == BK_Bool) printf("bool");
        else if (base == BK_String) printf("string");
        else if (base == BK_Void) printf("void");
        else printf("unknown");
        if (isArray()) {
            printf(", Array dims: [");
            for (size_t i = 0; i < sizes.size(); ++i) {
                printf("%d", sizes[i]);
                if (i < sizes.size() - 1) printf(", ");
            }
            printf("]");
        }
        if (isFunc()) {
            printf(", Function: (");
            for (size_t i = 0; i < params.size(); ++i) {
                params[i]->print();
                if (i < params.size() - 1) printf(", ");
            }
            printf(") -> ");
            ret->print();
        }
    }
};

struct TypeHash {
    std::size_t operator()(const Type& t) const;
};

class TypeArena {
public:
    ~TypeArena();
    Type* make(BaseKind kind);
    Type* makeArray(Type* elem, const std::vector<int>& sizes);
    Type* makeFunc(Type* ret, const std::vector<Type*>& params);

private:
    std::vector<Type*> types;
    std::unordered_map<Type, Type*, TypeHash> typeCache;
};


enum ValueKind { VK_None, VK_Int, VK_Float, VK_Bool, VK_String };

struct ExprInfo {
    Type* type;
    bool isConst;
    ValueKind valueKind;

    union {
        int iVal;
        float fVal;
        bool bVal;
    };
    std::string sVal;

    ExprInfo(Type* t, bool c = false)
        : type(t), isConst(c), valueKind(VK_None) {}

    void setInt(int v)    { valueKind = VK_Int; iVal = v; isConst = true; }
    void setFloat(float v){ valueKind = VK_Float; fVal = v; isConst = true; }
    void setBool(bool v)  { valueKind = VK_Bool; bVal = v; isConst = true; }
    void setString(const std::string& s) { valueKind = VK_String; sVal = s; isConst = true; }

    bool isZeroValue() const {
        if (!isConst) return false;
        switch (valueKind) {
            case VK_Int: return iVal == 0;
            case VK_Float: return fVal == 0.0f;
            case VK_Bool: return bVal == false;
            default: return false;
        }
    }

    void print() const {
        printf("ExprInfo: ");
        type->print();
        if (isConst) {
            printf(" Const = ");
            switch (valueKind) {
                case VK_Int:    printf("%d", iVal); break;
                case VK_Float:  printf("%f", fVal); break;
                case VK_Bool:   printf("%s", bVal ? "true" : "false"); break;
                case VK_String: printf("\"%s\"", sVal.c_str()); break;
                default: break;
            }
            if (isZeroValue()) printf(" (Zero)");
        }
        printf("\n");
    }

    int getInt() const {
        if (valueKind != VK_Int) throw std::runtime_error("Not an int value");
        return iVal;
    }

    float getFloat() const {
        if (valueKind != VK_Float) throw std::runtime_error("Not a float value");
        return fVal;
    }

    bool getBool() const {
        if (valueKind != VK_Bool) throw std::runtime_error("Not a bool value");
        return bVal;
    }

    std::string getString() const {
        if (valueKind != VK_String) throw std::runtime_error("Not a string value");
        return sVal;
    }
};

class Symbol {
public:
    std::string name;
    Type* type;
    bool isConst;

    ValueKind valueKind = VK_None;
    union {
        int iVal;
        float fVal;
        bool bVal;
    };
    std::string sVal;

    Symbol(const std::string& n, Type* t, bool c)
        : name(n), type(t), isConst(c), valueKind(VK_None) {}

    void setInt(int v)    { valueKind = VK_Int; iVal = v; }
    void setFloat(float v){ valueKind = VK_Float; fVal = v; }
    void setBool(bool v)  { valueKind = VK_Bool; bVal = v; }
    void setString(const std::string& s) { valueKind = VK_String; sVal = s; }

    bool hasConstValue() const {
        return isConst && valueKind != VK_None;
    }

    ExprInfo* getExpr() const {
        ExprInfo* e = new ExprInfo(type);
        if (!hasConstValue()) return e;

        e->isConst = true;

        switch (valueKind) {
            case VK_Int:
                e->setInt(iVal);
                break;
            case VK_Float:
                e->setFloat(fVal);
                break;
            case VK_Bool:
                e->setBool(bVal);
                break;
            case VK_String:
                e->setString(sVal);
                break;
            default:
                return nullptr;
        }
        return e;
    }

    void print() const {
        printf("Symbol: %s, ", name.c_str());
        type->print();
        if (isConst) {
            printf(" Const");
            if (hasConstValue()) {
                printf(" = ");
                switch (valueKind) {
                    case VK_Int: printf("%d", iVal); break;
                    case VK_Float: printf("%f", fVal); break;
                    case VK_Bool: printf("%s", bVal ? "true" : "false"); break;
                    case VK_String: printf("\"%s\"", sVal.c_str()); break;
                    default: break;
                }
            }
        }
        printf("\n");
    }
};
    


struct varInit{
    std::string* name;
    Type*       constType;
    std::vector<int>* arrayDims;
    varInit(std::string* n) : name(n), constType(0), arrayDims(0) {}
    varInit(std::string* n, Type* t) : name(n), constType(t), arrayDims(0) {}
    varInit(std::string* n, std::vector<int>* s) : name(n), constType(0), arrayDims(s) {}
};

/* ───── 符號表（作用域堆疊） ───── */
class SymbolTable {
public:
    void  enterScope() {
         scopes.push_back(Bucket());
     }
    void  leaveScope() { 
        printf("Leaving scope:\n");
        for (auto& s : scopes.back()) {
            s.second.print(); // 印出當前作用域的符號
        }
        scopes.pop_back(); }
    bool  insert(const Symbol& s);          // false=重複
    Symbol* lookup(const std::string&);     // 最近可見
    Symbol* lookupGlobal(const std::string&);

private:
    typedef std::unordered_map<std::string, Symbol> Bucket;
    std::vector<Bucket> scopes = std::vector<Bucket>(1);   // 全域 scope[0]
};

/* ───── 語意錯誤 ───── */
struct SemanticError : public std::runtime_error {
    int line;
    SemanticError(const std::string& m, int l) : std::runtime_error(m), line(l) {}
};

inline float toFloat(const ExprInfo* e) {
    return (e->valueKind == VK_Float) ? e->getFloat() : e->getInt();
}
inline int   toInt  (const ExprInfo* e) { return e->getInt(); }


enum NumOp { OPADD, OPSUB, OPMUL, OPDIV, OPMOD };
inline ExprInfo* numericResult(NumOp op,
                         ExprInfo* lhs, ExprInfo* rhs,
                         TypeArena& pool, int lineno)
{
    BaseKind b1 = lhs->type->base, b2 = rhs->type->base;
    bool isConst = lhs->isConst && rhs->isConst;

    // 僅允許 int/float
    if (!( (b1==BK_Int||b1==BK_Float) && (b2==BK_Int||b2==BK_Float) ))
        throw SemanticError("numeric type mismatch", lineno);

    // OPMOD 只允許 int
    if (op==OPMOD && (b1!=BK_Int || b2!=BK_Int))
        throw SemanticError("modulus type mismatch", lineno);

    // 除以零 / 餘零
    if ((op==OPDIV||op==OPMOD) && rhs->isZeroValue())
        throw SemanticError(op==OPDIV? "division by zero":"modulus by zero", lineno);

    BaseKind resKind = (b1==BK_Float||b2==BK_Float) ? BK_Float : BK_Int;
    ExprInfo* out = new ExprInfo(pool.make(resKind), isConst);

    if (isConst) {
        if (resKind==BK_Float) {
            float a = toFloat(lhs), b = toFloat(rhs);
            float r = (op==OPADD)? a+b : (op==OPSUB)? a-b :
                      (op==OPMUL)? a*b : (op==OPDIV)? a/b : a;   // OPMOD 不走這裡
            out->setFloat(r);
        } else {                               // int
            int a = lhs->getInt(), b = rhs->getInt();
            int r = (op==OPADD)? a+b : (op==OPSUB)? a-b :
                    (op==OPMUL)? a*b : (op==OPDIV)? a/b : a%b;
            out->setInt(r);
        }
    }
    return out;
}


enum RelOp { OPLT, OPLE, OPGT, OPGE };
inline ExprInfo* relResult(RelOp op,
                    ExprInfo* lhs, ExprInfo* rhs,
                    TypeArena& pool, int lineno)
{
    BaseKind b1 = lhs->type->base, b2 = rhs->type->base;
    bool isConst = lhs->isConst && rhs->isConst;

    if (!( (b1==BK_Int||b1==BK_Float) && (b2==BK_Int||b2==BK_Float) ))
        throw SemanticError("relational type mismatch", lineno);

    ExprInfo* out = new ExprInfo(pool.make(BK_Bool), isConst);
    if (isConst) {
        float a = toFloat(lhs), b = toFloat(rhs);
        bool r = (op==OPLT)? a<b : (op==OPLE)? a<=b : (op==OPGT)? a>b : a>=b;
        out->setBool(r);
    }
    return out;
}

inline ExprInfo* eqResult(bool equal, ExprInfo* lhs, ExprInfo* rhs, TypeArena& pool, int lineno) {
    BaseKind b1 = lhs->type->base, b2 = rhs->type->base;
    bool isConst = lhs->isConst && rhs->isConst;
    ExprInfo* out = new ExprInfo(pool.make(BK_Bool), isConst);

    auto cmpNum = [&](auto a, auto b){return equal ? a==b : a!=b;};

    if ((b1==BK_Int||b1==BK_Float) && (b2==BK_Int||b2==BK_Float)) {
        if (isConst) out->setBool(cmpNum(toFloat(lhs), toFloat(rhs)));
    }
    else if (b1==b2) {
        if (isConst) {
            switch (b1) {
                case BK_Bool:   out->setBool(cmpNum(lhs->getBool(),   rhs->getBool())); break;
                case BK_String: out->setBool(cmpNum(lhs->getString(), rhs->getString())); break;
                case BK_Int:    out->setBool(cmpNum(lhs->getInt(),    rhs->getInt())); break;
                case BK_Float:  out->setBool(cmpNum(lhs->getFloat(),  rhs->getFloat())); break;
                default: throw SemanticError("unsupported ==/!= type", lineno);
            }
        }
    } else
    throw SemanticError("equal type mismatch", lineno);

    return out;
}
