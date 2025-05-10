// SemanticError.cpp
#include "SemanticError.hpp"
#include <iostream>

std::vector<std::pair<int, std::string>> SemanticError::errors;

SemanticError::SemanticError(const std::string& msg, int ln)
    : std::runtime_error(msg), line(ln) {
    errors.emplace_back(ln, msg);
}

// 是否有錯誤
bool SemanticError::hasError() {
    return !errors.empty();
}

// 列印所有錯誤
void SemanticError::printAllError() {
    for (const auto& [line, msg] : errors) {
        std::cerr << "[Error] Line " << line << ": " << msg << "\n";
    }
}

// 清除錯誤
void SemanticError::clearError() {
    errors.clear();
}
