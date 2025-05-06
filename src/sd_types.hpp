#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <cstddef>
#include <cstdio>

/*───────── 型別系統 ─────────*/
enum BaseKind { BK_Int, BK_Float, BK_Bool, BK_String, BK_Void };

struct Type {
    BaseKind            base;
    int                 dim;          // 0 = scalar
    std::vector<int>    sizes;        // array dimensions
    std::vector<Type*>  params;       // function param types
    Type*               ret;          // function return

    explicit Type(BaseKind b) : base(b), dim(0), ret(nullptr) {}
    bool isArray() const { return dim > 0; }
    bool isFunc()  const { return ret || !params.empty(); }

    bool operator==(const Type& o) const;
    bool operator!=(const Type& o) const { return !(*this == o); }

    /* 方便除錯的小印法 */
    void dbgPrint() const {
        switch (base) {
            case BK_Int:    printf("int");    break;
            case BK_Float:  printf("float");  break;
            case BK_Bool:   printf("bool");   break;
            case BK_String: printf("string"); break;
            case BK_Void:   printf("void");   break;
        }
        if (isArray()) {
            printf(" array");
            for (int s: sizes) printf("[%d]", s);
        }
        if (isFunc()){
            printf(" function");
            if (ret) {
                printf(" -> ");
                ret->dbgPrint();
            }
            printf(" (");
            for (size_t i=0; i<params.size(); ++i) {
                params[i]->dbgPrint();
                if (i < params.size()-1) printf(", ");
            }
            printf(")");
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
    std::unordered_map<Type, Type*, TypeHash> cache;
};
