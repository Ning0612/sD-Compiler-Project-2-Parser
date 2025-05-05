#include "sd_common.hpp"


bool Type::operator==(const Type& o) const
{
    if (base != o.base || dim != o.dim || sizes != o.sizes) return false;
    if (params.size() != o.params.size()) return false;
    for (size_t i = 0; i < params.size(); ++i)
        if (!(*params[i] == *o.params[i])) return false;
    if (bool(ret) != bool(o.ret)) return false;
    if (ret && !(*ret == *o.ret)) return false;
    return true;
}

bool Type::operator!=(const Type& o) const
{
    return !(*this == o);
}

std::size_t TypeHash::operator()(const Type& t) const
{
    size_t h = std::hash<int>()(t.base) ^ std::hash<int>()(t.dim);
    for (auto s : t.sizes)
        h ^= std::hash<int>()(s) + 0x9e3779b9 + (h << 6) + (h >> 2);
    if (t.ret)
        h ^= operator()(*t.ret) + 0x9e3779b9 + (h << 6) + (h >> 2);
    for (auto* p : t.params)
        h ^= operator()(*p) + 0x9e3779b9 + (h << 6) + (h >> 2);
    if (t.isZero)
        h ^= std::hash<bool>()(t.isZero) + 0x9e3779b9 + (h << 6) + (h >> 2);
    return h;
}

/* ---- TypeArena ---- */
TypeArena::~TypeArena() {
    for (Type* t : types)
        delete t;
}

Type* TypeArena::make(BaseKind kind) {
    Type key(kind);
    auto it = typeCache.find(key);
    if (it != typeCache.end()) return it->second;

    Type* t = new Type(kind);
    types.push_back(t);
    typeCache[*t] = t;
    return t;
}

Type* TypeArena::make(BaseKind kind, bool isZero) {
    Type key(kind, isZero);
    auto it = typeCache.find(key);
    if (it != typeCache.end()) return it->second;

    Type* t = new Type(kind, isZero);
    types.push_back(t);
    typeCache[*t] = t;
    return t;
}

Type* TypeArena::makeArray(Type* elem, const std::vector<int>& sizes) {
    Type key = *elem;
    key.dim += 1;
    key.sizes = sizes;

    auto it = typeCache.find(key);
    if (it != typeCache.end()) return it->second;

    Type* t = new Type(key);
    types.push_back(t);
    typeCache[*t] = t;
    return t;
}

Type* TypeArena::makeFunc(Type* ret, const std::vector<Type*>& params) {
    Type key(BK_Void);
    key.ret = ret;
    key.params = params;

    auto it = typeCache.find(key);
    if (it != typeCache.end()) return it->second;

    Type* t = new Type(key);
    types.push_back(t);
    typeCache[*t] = t;
    return t;
}

/* ---- SymbolTable ---- */
bool SymbolTable::insert(const Symbol& s)
{
    Bucket& cur = scopes.back();
    return cur.insert(std::make_pair(s.name, s)).second;
}

Symbol* SymbolTable::lookup(const std::string& n)
{
    for (int i = scopes.size() - 1; i >= 0; --i) {
        Bucket::iterator it = scopes[i].find(n);
        if (it != scopes[i].end()) return &it->second;
    }
    return 0;
}

Symbol* SymbolTable::lookupGlobal(const std::string& n)
{
    Bucket::iterator it = scopes[0].find(n);
    return (it == scopes[0].end()) ? 0 : &it->second;
}

//  ---- SemanticError ----

Type* binaryNumericResult(Type* lhs, Type* rhs, TypeArena& pool, int line) {
    if ((lhs->base == BK_Int || lhs->base == BK_Float) &&
        (rhs->base == BK_Int || rhs->base == BK_Float)) {
        if (lhs->base == BK_Float || rhs->base == BK_Float)
            return pool.make(BK_Float);
        else
            return pool.make(BK_Int);
    }
    throw SemanticError("Type Error: Binary operator on non-numeric types", line);
}

Type* binaryModResult(Type* lhs, Type* rhs, TypeArena& pool, int line) {
    if (rhs->isZero) {
        throw SemanticError("Type Error: Mod operator on zero", line);
    }
    if (lhs->base == BK_Int && rhs->base == BK_Int)
        return pool.make(BK_Int);
    throw SemanticError("Type Error: Mod operator on non-int types", line);
}

Type * unaryNumericResult(Type* t, TypeArena& pool, int line) {
    if (t->base == BK_Int || t->base == BK_Float)
        return t;
    throw SemanticError("Type Error: Unary operator on non-numeric type", line);
}

Type* unaryBoolResult(Type* t, TypeArena& pool, int line) {
    if (t->base == BK_Bool)
        return t;
    throw SemanticError("Type Error: Unary operator on non-bool type", line);
}

Type* binaryBoolResult(Type* lhs, Type* rhs, TypeArena& pool, int line) {
    if (lhs->base == BK_Bool && rhs->base == BK_Bool)
        return pool.make(BK_Bool);
    throw SemanticError("Type Error: Binary operator on non-bool types", line);
}

Type* binaryCompareResult(Type* lhs, Type* rhs, TypeArena& pool, int line) {
    if ((lhs->base == BK_Int || lhs->base == BK_Float) &&
        (rhs->base == BK_Int || rhs->base == BK_Float))
        return pool.make(BK_Bool);
    throw SemanticError("Type Error: Binary operator on non-comparable types", line);
}

Type* binaryEqualNotEqualResult(Type* lhs, Type* rhs, TypeArena& pool, int line) {
    if (lhs->base == rhs->base && lhs->base != BK_Void )
        return pool.make(BK_Bool);
    throw SemanticError("Type Error: Binary operator on non-equal types", line);
}