#pragma once
#include "expr.hpp"
#include <unordered_map>
#include <string>
#include <cstdio>

/*───────── Symbol & SymbolTable ─────────*/
class Symbol {
public:
    std::string name;
    Type* type;
    bool  isConst;

    ValueKind valueKind = VK_None;
    union { int iVal; float fVal; bool bVal; };
    std::string sVal;

    Symbol(const std::string& n, Type* t, bool c)
        : name(n), type(t), isConst(c) {}

    /* 設常數值 */
    void setInt(int v){ valueKind=VK_Int; iVal=v; }
    void setFloat(float v){ valueKind=VK_Float; fVal=v; }
    void setBool(bool v){ valueKind=VK_Bool; bVal=v; }
    void setString(const std::string& s){ valueKind=VK_String; sVal=s; }
    bool hasConstValue() const { return isConst && valueKind!=VK_None; }
    void setConstValueFromExpr(const ExprInfo* e);

    ExprInfo* getExpr() const;          // 定義在 symtab.cpp
    void      dbgPrint() const;         // 定義在 symtab.cpp
};

class SymbolTable {
    using Bucket = std::unordered_map<std::string,Symbol>;
    std::vector<Bucket> scopes { Bucket() };   // scopes[0] = global
public:
    void enterScope(){ scopes.emplace_back(); }
    void leaveScope();
    bool insert(const Symbol& s);              // false=duplicate
    Symbol* lookup(const std::string& name);   // nearest
    Symbol* lookupGlobal(const std::string& name);
    void dbgPrintCurrentScope() const;
};
