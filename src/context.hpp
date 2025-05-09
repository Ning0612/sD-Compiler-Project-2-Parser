// context.hpp
#pragma once
#include "sem_utils.hpp"

struct Context {
    SymbolTable symTab;
    TypeArena typePool;
    std::vector<std::pair<ExprInfo, int>> returnsExpr;
};