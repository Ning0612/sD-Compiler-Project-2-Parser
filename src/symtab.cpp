#include "symtab.hpp"

/*--------- Symbol ---------*/
ExprInfo* Symbol::getExpr() const {
    ExprInfo* e = new ExprInfo(type);
    if(!hasConstValue()) return e;
    switch(valueKind){
        case VK_Int:    e->setInt(iVal);       break;
        case VK_Float:  e->setFloat(fVal);     break;
        case VK_Bool:   e->setBool(bVal);      break;
        case VK_String: e->setString(sVal);    break;
        default: break;
    }
    return e;
}

void Symbol::dbgPrint() const {
    printf("Symbol: %s", name.c_str());
    printf(", Type: ");
    type->dbgPrint();
    if(isConst){
        printf(", Const");
        if(hasConstValue()){
            printf(" = ");
            switch(valueKind){
                case VK_Int:   printf("%d", iVal); break;
                case VK_Float: printf("%f", fVal); break;
                case VK_Bool:  printf("%s", bVal?"true":"false"); break;
                case VK_String:printf("\"%s\"", sVal.c_str()); break;
                default: break;
            }
        }
    }
    puts("");
}

/*--------- SymbolTable ------*/
bool SymbolTable::insert(const Symbol& s){
    return scopes.back().insert({s.name,s}).second;
}

Symbol* SymbolTable::lookup(const std::string& n){
    for(int i=scopes.size()-1;i>=0;--i){
        auto it=scopes[i].find(n);
        if(it!=scopes[i].end()) return &it->second;
    }
    return nullptr;
}

Symbol* SymbolTable::lookupGlobal(const std::string& n){
    auto it=scopes[0].find(n);
    return it==scopes[0].end()? nullptr : &it->second;
}

void SymbolTable::leaveScope(){
    printf("\nLeaving scope:\n");
    for(auto& p: scopes.back()) p.second.dbgPrint();
    scopes.pop_back();
}
