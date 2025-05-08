#pragma once
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

class SemanticError : public std::runtime_error {
public:
    int line;

    SemanticError(const std::string& msg, int ln)
        : std::runtime_error(msg), line(ln) {
        errors.emplace_back(ln, msg);
    }

    // 儲存所有錯誤
    static std::vector<std::pair<int, std::string>> errors;

    // 是否有錯誤
    static bool hasError() {
        return !errors.empty();
    }

    // 列印所有錯誤
    static void printAll() {
        for (const auto& [line, msg] : errors) {
            std::cerr << "[Error] Line " << line << ": " << msg << "\n";
        }
    }

    // 清除錯誤
    static void clear() {
        errors.clear();
    }
};
