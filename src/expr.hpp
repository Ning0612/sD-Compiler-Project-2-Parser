#pragma once
#include "sd_types.hpp"
#include <stdexcept>
#include <string>

// Enumeration to indicate the kind of constant value stored
enum ValueKind { VK_None, VK_Int, VK_Float, VK_Double, VK_Bool, VK_String };

// Structure to represent expression information during semantic analysis
struct ExprInfo {
    Type* type;             // Expression's semantic type
    bool isConst;           // Whether the expression is a constant
    ValueKind valueKind;    // What kind of value is stored

    // Union for storing scalar constant values
    union {
        int iVal;
        float fVal;
        double dVal;
        bool bVal;
    };

    std::string sVal;       // Separate member for string constants

    // Constructor initializes the expression info
    explicit ExprInfo(Type* t, bool c = false);

    // Setters for different constant values
    void setInt(int v);
    void setFloat(float v);
    void setDouble(double v);
    void setBool(bool v);
    void setString(const std::string& s);

    // Check if the constant value is logically "zero"
    bool isZeroValue() const;

    // Getters for constant values, will throw if type mismatched
    int getInt() const;
    float getFloat() const;
    double getDouble() const;
    bool getBool() const;
    std::string getString() const;

    // Copy constant value from another expression
    void setConstValueFromExpr(const ExprInfo* e);
};
