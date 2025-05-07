#include "sd_types.hpp"

/*--------- Type equality ---------*/

bool isBaseCompatible(BaseKind a, BaseKind b) {
    if (a == b) return true;

    // 定義寬容相容的基本型別對應邏輯
    if ((a == BK_Int && (b == BK_Float || b == BK_Double)) ||
        (a == BK_Float && (b == BK_Int || b == BK_Double)) ||
        (a == BK_Double && (b == BK_Int || b == BK_Float)))
        return true;

    return false;
}

BaseKind promote(BaseKind b1, BaseKind b2) {
    if (b1 == BK_Double || b2 == BK_Double)
        return BK_Double;
    if (b1 == BK_Float || b2 == BK_Float)
        return BK_Float;
    return BK_Int;
}

bool Type::operator==(const Type& o) const {
    // 比較型別：Array 或 Function 必須一致
    if (this->isArray() != o.isArray()) return false;
    if (this->isFunc() != o.isFunc()) return false;

    // 若為 Array，需比較維度與大小
    if (this->isArray()) {
        if (dim != o.dim || sizes != o.sizes)
            return false;
    }

    // 若為 Function，需比較參數與回傳值型別
    if (this->isFunc()) {
        if (params.size() != o.params.size())
            return false;
        for (size_t i = 0; i < params.size(); ++i)
            if (!(*params[i] == *o.params[i]))
                return false;
        if (*ret != *o.ret)
            return false;
    }

    // 比較基本型別（如 int、float 等）
    return base == o.base;
}

bool Type::isCompatibleWith(const Type& o) const {
    // Array 或 Function 型別必須完全一致
    if (this->isArray() || this->isFunc() || o.isArray() || o.isFunc())
        return *this == o; // 使用嚴格相等比對

    // 非 array、非 function，則允許基本型別寬容轉換
    return isBaseCompatible(this->base, o.base);
}


/*--------- Type hashing ----------*/
std::size_t TypeHash::operator()(const Type& t) const {
    std::size_t h = std::hash<int>()(t.base) ^ std::hash<int>()(t.dim);
    for (int s: t.sizes) h ^= std::hash<int>()(s)+0x9e3779b9+(h<<6)+(h>>2);
    if (t.ret) h ^= operator()(*t.ret)+0x9e3779b9+(h<<6)+(h>>2);
    for (auto* p: t.params) h ^= operator()(*p)+0x9e3779b9+(h<<6)+(h>>2);
    return h;
}

/*--------- TypeArena -------------*/
TypeArena::~TypeArena(){ for(Type* t:types) delete t; }

Type* TypeArena::make(BaseKind k){
    Type key(k);
    auto it=cache.find(key);
    if(it!=cache.end()) return it->second;
    Type* t=new Type(k); types.push_back(t); cache[*t]=t; return t;
}

Type* TypeArena::makeArray(Type* elem,const std::vector<int>& sz){
    Type key=*elem; key.dim=sz.size(); key.sizes=sz;
    auto it=cache.find(key); if(it!=cache.end()) return it->second;
    Type* t=new Type(key); types.push_back(t); cache[*t]=t; return t;
}

Type* TypeArena::makeFunc(Type* ret,const std::vector<Type*>& p){
    Type key(ret->base); key.ret=ret; key.params=p;
    auto it=cache.find(key); if(it!=cache.end()) return it->second;
    Type* t=new Type(key); types.push_back(t); cache[*t]=t; return t;
}

std::string baseKindToStr(BaseKind kind) {
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