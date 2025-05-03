#include "sd_common.hpp"
#include <sstream>

/* -------- Type -------- */
std::shared_ptr<Type> Type::array(std::shared_ptr<Type> elem, std::vector<int> sz){
    auto t = std::make_shared<Type>(*elem);
    t->dim = elem->dim + 1;
    t->sizes = sz;
    return t;
}

std::shared_ptr<Type> Type::func(std::shared_ptr<Type> r, std::vector<std::shared_ptr<Type>> ps){
    auto t   = std::make_shared<Type>();
    t->base  = BaseKind::Void;      // 本身不是 scalar
    t->params= std::move(ps);
    t->ret   = std::move(r);
    return t;
}

bool Type::operator==(const Type& o) const{
    if (base != o.base || dim != o.dim) return false;
    if (sizes != o.sizes) return false;
    if (params.size() != o.params.size()) return false;
    for (size_t i = 0; i < params.size(); ++i)
        if (*params[i] != *o.params[i]) return false;
    if (bool(ret) != bool(o.ret)) return false;
    if (ret && *ret != *o.ret) return false;
    return true;
}

/* -------- SymbolTable -------- */
void SymbolTable::enterScope()  { scopes.emplace_back(); }
void SymbolTable::leaveScope()  { scopes.pop_back();     }

bool SymbolTable::insert(const Symbol& s)
{
    auto& cur = scopes.back();
    return cur.emplace(s.name, s).second;
}

Symbol* SymbolTable::lookup(const std::string& n)
{
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto f = it->find(n);
        if (f != it->end()) return &f->second;
    }
    return nullptr;
}
Symbol* SymbolTable::lookupGlobal(const std::string& n)
{
    auto& g = scopes.front();
    auto f  = g.find(n);
    return f == g.end() ? nullptr : &f->second;
}

/* -------- SemanticError -------- */
SemanticError::SemanticError(const std::string& msg, int ln)
    : std::runtime_error(msg), lineNo(ln) {}
