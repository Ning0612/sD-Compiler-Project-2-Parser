#pragma once
#include <string>
#include <vector>
#include "sd_types.hpp"  // 如果要用 Type*

struct varInit {
    std::string* name;
    Type*        constType;
    std::vector<int>* arrayDims;

    varInit(std::string* n)
        : name(n), constType(nullptr), arrayDims(nullptr) {}

    varInit(std::string* n, Type* t)
        : name(n), constType(t), arrayDims(nullptr) {}

    varInit(std::string* n, std::vector<int>* s)
        : name(n), constType(nullptr), arrayDims(s) {}
};
