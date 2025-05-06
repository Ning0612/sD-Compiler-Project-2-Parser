#include "sd_types.hpp"

/*--------- Type equality ---------*/
bool Type::operator==(const Type& o) const {
    if (base != o.base || dim != o.dim || sizes != o.sizes) return false;
    if (params.size() != o.params.size()) return false;
    for (size_t i=0;i<params.size();++i)
        if (!(*params[i] == *o.params[i])) return false;
    if (bool(ret)!=bool(o.ret)) return false;
    return ret ? (*ret == *o.ret) : true;
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
