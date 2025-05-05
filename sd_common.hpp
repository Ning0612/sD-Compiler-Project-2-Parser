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
    bool                isZero;          // 是否為 0 

    Type(BaseKind b) : base(b), dim(0), ret(0), isZero(false){}
    Type(BaseKind b, bool z) : base(b), dim(0), ret(0), isZero(z){}

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
    Type* make(BaseKind kind, bool isZero);
    Type* makeArray(Type* elem, const std::vector<int>& sizes);
    Type* makeFunc(Type* ret, const std::vector<Type*>& params);

private:
    std::vector<Type*> types;
    std::unordered_map<Type, Type*, TypeHash> typeCache;
};

/* ───── 符號表項 ───── */
class Symbol {
    public:
    std::string name;
    Type*       type;
    bool        isConst;
    Symbol(const std::string& n, Type* t, bool c) : name(n), type(t), isConst(c) {}
    void print() const {
        printf("Symbol: %s, ", name.c_str());
        type->print();
        if (isConst) printf(" Const");
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


Type* binaryNumericResult(Type* lhs, Type* rhs, TypeArena& pool, int line);
Type* binaryModResult(Type* lhs, Type* rhs, TypeArena& pool, int line) ;
Type * unaryNumericResult(Type* t, TypeArena& pool, int line) ;
Type* unaryBoolResult(Type* t, TypeArena& pool, int line) ;
Type* binaryBoolResult(Type* lhs, Type* rhs, TypeArena& pool, int line) ;
Type* binaryCompareResult(Type* lhs, Type* rhs, TypeArena& pool, int line) ;
Type* binaryEqualNotEqualResult(Type* lhs, Type* rhs, TypeArena& pool, int line) ;