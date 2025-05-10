// SemanticError.hpp: This file contains the definition of the SemanticError class, which is used to handle semantic errors in the compiler.

#pragma once
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

class SemanticError : public std::runtime_error {
public:
    int line;

    SemanticError(const std::string& msg, int ln);
    // 儲存所有錯誤
    static std::vector<std::pair<int, std::string>> errors;

    // 是否有錯誤
    static bool hasError();

    // 列印所有錯誤
    static void printAllError();

    // 清除錯誤
    static void clearError();
};