// var_init.cpp
#pragma once

#include <string>
#include <vector>
#include "sd_types.hpp"

// Represents a variable declaration, which may be a scalar or an array
struct VarInit {
    std::string name;             // Variable name
    Type* constType;              // Type of the variable (null if array dimensions are provided)
    std::vector<int> arrayDims;   // Array dimensions if the variable is an array
    bool isValid;

    // Constructor for an untyped variable (usually resolved later)
    VarInit(std::string n);

    // Constructor for a typed scalar variable
    VarInit(std::string n, Type* t);

    // Constructor for an array variable with dimensions
    VarInit(std::string n, std::vector<int> s);
};

VarInit* makeInvalidVar();
