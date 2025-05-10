#pragma once

#include "ExprInfo.hpp"
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