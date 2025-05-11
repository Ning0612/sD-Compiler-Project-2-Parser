// SdTypes.cpp
#include "SdTypes.hpp"
#include <cstdio>

/*--------- Type Equality and Compatibility ---------*/

bool isConvertible(BaseKind a, BaseKind b) {
    return (a == BK_Int    && (b == BK_Float || b == BK_Double)) ||
           (a == BK_Float  && (b == BK_Int || b == BK_Double))   ||
           (a == BK_Double && (b == BK_Int || b == BK_Float));
}

bool isBaseCompatible(BaseKind a, BaseKind b) {
    return a == b || isConvertible(a, b);
}

BaseKind promote(BaseKind b1, BaseKind b2) {
    if (b1 == BK_Double || b2 == BK_Double) return BK_Double;
    if (b1 == BK_Float  || b2 == BK_Float)  return BK_Float;
    return BK_Int;
}

/*--------- Type Methods ---------*/

Type::Type(BaseKind b): base(b), dim(0), ret(nullptr) {}

// Check if the type is scalar, array, or function
bool Type::isScalar() const { return !isArray() && !isFunc(); }
bool Type::isArray() const  { return dim > 0; }
bool Type::isFunc() const   { return ret || !params.empty(); }

// Check if the type is compatible with another type
bool Type::operator==(const Type& o) const {
    if (this->isArray() != o.isArray()) return false;
    if (this->isFunc()  != o.isFunc())  return false;

    if (isArray()) {
        if (dim != o.dim || sizes != o.sizes)
            return false;
    }

    if (isFunc()) {
        if (params.size() != o.params.size()) return false;
        for (size_t i = 0; i < params.size(); ++i)
            if (!(*params[i] == *o.params[i]))
                return false;
        if (*ret != *o.ret)
            return false;
    }

    return base == o.base;
}

bool Type::operator!=(const Type& o) const {
    return !(*this == o);
}

// Check if the type is compatible with another type
bool Type::isCompatibleWith(const Type& o) const {
    if (this->isArray() || this->isFunc() || o.isArray() || o.isFunc())
        return *this == o;

    return isBaseCompatible(this->base, o.base);
}

// Debug print for the type
void Type::dbgPrint() const {
    std::printf("%s", baseKindToStr(base).c_str());

    if (isArray()) {
        std::printf(" array");
        for (int s : sizes)
            std::printf("[%d]", s);
    }

    if (isFunc()) {
        std::printf(" function");
        if (ret) {
            std::printf(" -> return ");
            ret->dbgPrint();
        }
        std::printf(", params: (");
        for (size_t i = 0; i < params.size(); ++i) {
            params[i]->dbgPrint();
            if (i + 1 < params.size()) std::printf(", ");
        }
        std::printf(")");
    }
}

/*--------- Type Hashing ---------*/

std::size_t TypeHash::operator()(const Type& t) const {
    std::size_t h = std::hash<int>()(t.base) ^ std::hash<int>()(t.dim);
    for (int s : t.sizes)
        h ^= std::hash<int>()(s) + 0x9e3779b9 + (h << 6) + (h >> 2);
    if (t.ret)
        h ^= operator()(*t.ret) + 0x9e3779b9 + (h << 6) + (h >> 2);
    for (Type* p : t.params)
        h ^= operator()(*p) + 0x9e3779b9 + (h << 6) + (h >> 2);
    return h;
}

/*--------- TypeArena Implementation ---------*/

// Destructor for TypeArena, cleans up all allocated types
TypeArena::~TypeArena() {
    for (Type* t : types)
        delete t;
}

// Create a new type or return an existing one from the cache
Type* TypeArena::make(BaseKind kind) {
    Type key(kind);
    auto it = cache.find(key);
    if (it != cache.end()) return it->second;

    Type* t = new Type(kind);
    types.push_back(t);
    cache[*t] = t;
    return t;
}

// Create a new array type or return an existing one from the cache
Type* TypeArena::makeArray(Type* elem, const std::vector<int>& sizes) {
    Type key = *elem;
    key.dim = sizes.size();
    key.sizes = sizes;

    auto it = cache.find(key);
    if (it != cache.end()) return it->second;

    Type* t = new Type(key);
    types.push_back(t);
    cache[*t] = t;
    return t;
}

// Create a new function type or return an existing one from the cache
Type* TypeArena::makeFunc(Type* ret, const std::vector<Type*>& params) {
    Type key(ret->base);
    key.ret = ret;
    key.params = params;

    auto it = cache.find(key);
    if (it != cache.end()) return it->second;

    Type* t = new Type(key);
    types.push_back(t);
    cache[*t] = t;
    return t;
}

/*--------- Utility ---------*/

std::string baseKindToStr(BaseKind kind) {
    switch (kind) {
        case BK_Int:    return "int";
        case BK_Float:  return "float";
        case BK_Double: return "double";
        case BK_Bool:   return "bool";
        case BK_String: return "string";
        case BK_Void:   return "void";
        default:        return "unknown";
    }
}
