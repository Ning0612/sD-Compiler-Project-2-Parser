#include "SymbolTable.hpp"
#include <cstdio>

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
    printf("\n======= Symbol Table in scope [%ld] =======\n", scopes.size() - 1);
    for (const auto& p : scopes.back()) {
        p.second.dbgPrint();
    }
    printf("\n");
}
