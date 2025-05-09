// var_init.cpp
#include "var_init.hpp"

// Constructor for variable without type (used for basic declaration)
VarInit::VarInit(std::string n)
    : name(n), constType(nullptr), arrayDims() {}

// Constructor for variable with specified type
VarInit::VarInit(std::string n, Type* t)
    : name(n), constType(t), arrayDims() {}

// Constructor for array variable with given dimensions
VarInit::VarInit(std::string n, std::vector<int> s)
    : name(n), constType(nullptr), arrayDims(s) {}
