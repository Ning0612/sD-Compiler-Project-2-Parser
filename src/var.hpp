#pragma once
#include <string>
#include <vector>
#include "sd_types.hpp"  // 如果要用 Type*

struct VarInit {
    std::string name;
    Type*        constType;
    std::vector<int> arrayDims;

    VarInit(std::string n)
        : name(n), constType(nullptr), arrayDims() {}

    VarInit(std::string n, Type* t)
        : name(n), constType(t), arrayDims() {}

    VarInit(std::string n, std::vector<int> s)
        : name(n), constType(nullptr), arrayDims(s) {}
};
