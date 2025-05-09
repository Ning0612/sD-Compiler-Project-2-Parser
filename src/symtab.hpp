#pragma once

#include "expr.hpp"
#include <string>
#include <vector>
#include <unordered_map>

/* ───────────── Symbol ─────────────
   Represents a declared symbol in the program:
   variable, constant, or function argument.
*/
class Symbol {
public:
    std::string name;      // symbol name
    Type* type;            // symbol type
    bool isConst;          // whether the symbol is constant

    ValueKind valueKind = VK_None;  // constant value kind
    union {
        int iVal;
        float fVal;
        double dVal;
        bool bVal;
    };
    std::string sVal; // string constants

    Symbol(const std::string& n, Type* t, bool c);

    void setInt(int v);
    void setFloat(float v);
    void setDouble(double v);
    void setBool(bool v);
    void setString(const std::string& s);
    bool hasConstValue() const;
    void setConstValueFromExpr(const ExprInfo* e);

    ExprInfo* getExpr() const;
    void dbgPrint() const;
};

/* ───────────── SymbolTable ─────────────
   Manages scopes and symbol declarations.
   Supports nested scopes (stack-based).
*/
class SymbolTable {
    using Bucket = std::unordered_map<std::string, Symbol>;
    std::vector<Bucket> scopes { Bucket() }; // scopes[0] = global scope

public:
    void enterScope();                          // push new scope
    void leaveScope();                          // pop current scope
    bool insert(const Symbol& s);               // insert symbol into current scope
    Symbol* lookup(const std::string& name);    // search from innermost to outermost
    Symbol* lookupGlobal(const std::string& name); // search global scope only
    void dbgPrintCurrentScope() const;
};
