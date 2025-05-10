// context.hpp
#pragma once
#include "SemanticAnalyzer.hpp"

struct Context {
    SymbolTable symTab;
    TypeArena typePool;
    std::vector<std::pair<ExprInfo, int>> returnsExpr;
    Type* nowType = nullptr;
};