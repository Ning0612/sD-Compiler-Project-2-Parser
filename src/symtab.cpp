#include "symtab.hpp"

/*--------- Symbol ---------*/
ExprInfo* Symbol::getExpr() const {
    ExprInfo* e = new ExprInfo(type);
    if(!hasConstValue()) return e;
    switch(valueKind){
        case VK_Int:    e->setInt(iVal);       break;
        case VK_Float:  e->setFloat(fVal);     break;
        case VK_Double: e->setDouble(dVal);    break;
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
                case VK_Double:printf("%f", dVal); break;
                case VK_Bool:  printf("%s", bVal?"true":"false"); break;
                case VK_String:printf("\"%s\"", sVal.c_str()); break;
                default: break;
            }
        }
    }
    puts("");
}

void Symbol::setConstValueFromExpr(const ExprInfo* e) {
    switch (type->base) {
        case BK_Int:
            if (e->valueKind == VK_Int)       setInt(e->getInt());
            else if (e->valueKind == VK_Float)  setInt(static_cast<int>(e->getFloat()));
            else if (e->valueKind == VK_Double) setInt(static_cast<int>(e->getDouble()));
            break;

        case BK_Float:
            if (e->valueKind == VK_Int)        setFloat(static_cast<float>(e->getInt()));
            else if (e->valueKind == VK_Float) setFloat(e->getFloat());
            else if (e->valueKind == VK_Double)setFloat(static_cast<float>(e->getDouble()));
            break;

        case BK_Double:
            if (e->valueKind == VK_Int)        setDouble(static_cast<double>(e->getInt()));
            else if (e->valueKind == VK_Float) setDouble(static_cast<double>(e->getFloat()));
            else if (e->valueKind == VK_Double)setDouble(e->getDouble());
            break;

        case BK_Bool:
            if (e->valueKind == VK_Bool) setBool(e->getBool());
            break;

        case BK_String:
            if (e->valueKind == VK_String) setString(e->getString());
            break;

        default: break;
    }
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
    this->dbgPrintCurrentScope();
    scopes.pop_back();
}

void SymbolTable::dbgPrintCurrentScope() const {
    printf("\nSymbol Table in scope [%ld]\n", this->scopes.size()-1);

    for (const auto& p : scopes.back()) {
        p.second.dbgPrint();
    }
}