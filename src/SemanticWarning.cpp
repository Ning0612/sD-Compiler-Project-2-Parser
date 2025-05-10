#include "SemanticWarning.hpp"
#include <iostream>

// 靜態成員定義
std::vector<std::pair<int, std::string>> SemanticWarning::warnings;

// 建構子
SemanticWarning::SemanticWarning(const std::string& msg, int ln)
    : std::runtime_error(msg), line(ln) {
    warnings.emplace_back(ln, msg);
}

// 是否有警告
bool SemanticWarning::hasWarning() {
    return !warnings.empty();
}

// 列印所有警告
void SemanticWarning::printAllWarning() {
    for (const auto& [line, msg] : warnings) {
        std::cerr << "[Warning] Line " << line << ": " << msg << "\n";
    }
}

// 清除警告
void SemanticWarning::clearWarning() {
    warnings.clear();
}
