#include "symtab.hpp"
#include <cstdio>

/* ───────────── Symbol Methods ───────────── */

Symbol::Symbol(const std::string& n, Type* t, bool c)
    : name(n), type(t), isConst(c) {}

void Symbol::setInt(int v) { valueKind = VK_Int; iVal = v; }
void Symbol::setFloat(float v) { valueKind = VK_Float; fVal = v; }
void Symbol::setDouble(double v) { valueKind = VK_Double; dVal = v; }
void Symbol::setBool(bool v) { valueKind = VK_Bool; bVal = v; }
void Symbol::setString(const std::string& s) { valueKind = VK_String; sVal = s; }

// Check if the symbol has a constant value
// A symbol is considered to have a constant value if it is marked as constant
bool Symbol::hasConstValue() const {
    return isConst && valueKind != VK_None;
}

// Set the constant value from another expression
// Converts the value to the symbol's type if necessary
void Symbol::setConstValueFromExpr(const ExprInfo* e) {
    switch (type->base) {
        case BK_Int:
            if (e->valueKind == VK_Int) setInt(e->getInt());
            else if (e->valueKind == VK_Float) setInt(static_cast<int>(e->getFloat()));
            else if (e->valueKind == VK_Double) setInt(static_cast<int>(e->getDouble()));
            break;

        case BK_Float:
            if (e->valueKind == VK_Int) setFloat(static_cast<float>(e->getInt()));
            else if (e->valueKind == VK_Float) setFloat(e->getFloat());
            else if (e->valueKind == VK_Double) setFloat(static_cast<float>(e->getDouble()));
            break;

        case BK_Double:
            if (e->valueKind == VK_Int) setDouble(static_cast<double>(e->getInt()));
            else if (e->valueKind == VK_Float) setDouble(static_cast<double>(e->getFloat()));
            else if (e->valueKind == VK_Double) setDouble(e->getDouble());
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

// Get the expression information for the symbol
ExprInfo* Symbol::getExpr() const {
    ExprInfo* e = new ExprInfo(type);
    if (!hasConstValue()) return e;

    switch (valueKind) {
        case VK_Int:    e->setInt(iVal); break;
        case VK_Float:  e->setFloat(fVal); break;
        case VK_Double: e->setDouble(dVal); break;
        case VK_Bool:   e->setBool(bVal); break;
        case VK_String: e->setString(sVal); break;
        default: break;
    }

    return e;
}

// Debug print the symbol's information
// Prints the symbol's name, type, and constant value if applicable
// The output format is: "Symbol: <name>, Type: <type>, Const = <value>"
// If the symbol is not constant, it will not print the value
// If the symbol is a string, it will print the value in double quotes
// If the symbol is a numeric type, it will print the value as is
// If the symbol is a boolean, it will print "true" or "false"
void Symbol::dbgPrint() const {
    printf("Symbol: %s, Type: ", name.c_str());
    type->dbgPrint();

    if (isConst) {
        printf(", Const");
        if (hasConstValue()) {
            printf(" = ");
            switch (valueKind) {
                case VK_Int:    printf("%d", iVal); break;
                case VK_Float:  printf("%f", fVal); break;
                case VK_Double: printf("%f", dVal); break;
                case VK_Bool:   printf("%s", bVal ? "true" : "false"); break;
                case VK_String: printf("\"%s\"", sVal.c_str()); break;
                default: break;
            }
        }
    }
    puts("");
}

/* ───────────── SymbolTable Methods ───────────── */

// Enter a new scope by pushing a new bucket onto the stack
void SymbolTable::enterScope() {
    scopes.emplace_back();
}

// Leave the current scope by popping the last bucket from the stack
void SymbolTable::leaveScope() {
    dbgPrintCurrentScope();
    scopes.pop_back();
}

// Insert a symbol into the current scope
// Returns true if the symbol was successfully inserted, false if it already exists
bool SymbolTable::insert(const Symbol& s) {
    return scopes.back().insert({s.name, s}).second;
}

// Lookup a symbol by name, searching from the innermost to the outermost scope
// Returns a pointer to the symbol if found, or nullptr if not found
Symbol* SymbolTable::lookup(const std::string& n) {
    for (int i = scopes.size() - 1; i >= 0; --i) {
        auto it = scopes[i].find(n);
        if (it != scopes[i].end()) return &it->second;
    }
    return nullptr;
}

// Lookup a symbol in the global scope only
// Returns a pointer to the symbol if found, or nullptr if not found
Symbol* SymbolTable::lookupGlobal(const std::string& n) {
    auto it = scopes[0].find(n);
    return (it != scopes[0].end()) ? &it->second : nullptr;
}

// Debug print the current scope's symbols
// Prints the scope index and each symbol's details
void SymbolTable::dbgPrintCurrentScope() const {
    printf("\nSymbol Table in scope [%ld]\n", scopes.size() - 1);
    for (const auto& p : scopes.back()) {
        p.second.dbgPrint();
    }
}
