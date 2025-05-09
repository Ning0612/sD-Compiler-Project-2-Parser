#include "expr.hpp"

// Constructor: initialize type and constness
ExprInfo::ExprInfo(Type* t, bool c)
    : type(t), isConst(c), valueKind(VK_None) {}

// Set integer value and mark as constant
void ExprInfo::setInt(int v) {
    valueKind = VK_Int;
    iVal = v;
    isConst = true;
}

// Set float value and mark as constant
void ExprInfo::setFloat(float v) {
    valueKind = VK_Float;
    fVal = v;
    isConst = true;
}

// Set double value and mark as constant
void ExprInfo::setDouble(double v) {
    valueKind = VK_Double;
    dVal = v;
    isConst = true;
}

// Set boolean value and mark as constant
void ExprInfo::setBool(bool v) {
    valueKind = VK_Bool;
    bVal = v;
    isConst = true;
}

// Set string value and mark as constant
void ExprInfo::setString(const std::string& s) {
    valueKind = VK_String;
    sVal = s;
    isConst = true;
}

// Return true if the constant value is logically zero (0, 0.0, "", false, etc.)
bool ExprInfo::isZeroValue() const {
    if (!isConst) return false;
    switch (valueKind) {
        case VK_Int:    return iVal == 0;
        case VK_Float:  return fVal == 0.0f;
        case VK_Double: return dVal == 0.0;
        case VK_String: return sVal.empty();
        case VK_Bool:   return bVal == false;
        default:        return false;
    }
}

// Getter: returns int value or throws if not int
int ExprInfo::getInt() const {
    if (valueKind != VK_Int) throw std::runtime_error("not int");
    return iVal;
}

// Getter: returns float value or throws if not float
float ExprInfo::getFloat() const {
    if (valueKind != VK_Float) throw std::runtime_error("not float");
    return fVal;
}

// Getter: returns double value or throws if not double
double ExprInfo::getDouble() const {
    if (valueKind != VK_Double) throw std::runtime_error("not double");
    return dVal;
}

// Getter: returns bool value or throws if not bool
bool ExprInfo::getBool() const {
    if (valueKind != VK_Bool) throw std::runtime_error("not bool");
    return bVal;
}

// Getter: returns string value or throws if not string
std::string ExprInfo::getString() const {
    if (valueKind != VK_String) throw std::runtime_error("not string");
    return sVal;
}

// Copy constant value from another ExprInfo object
void ExprInfo::setConstValueFromExpr(const ExprInfo* e) {
    switch (e->valueKind) {
        case VK_Int:    setInt(e->getInt()); break;
        case VK_Float:  setFloat(e->getFloat()); break;
        case VK_Double: setDouble(e->getDouble()); break;
        case VK_Bool:   setBool(e->getBool()); break;
        case VK_String: setString(e->getString()); break;
        default: break;
    }
}
