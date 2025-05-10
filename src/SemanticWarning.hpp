// SemanticWarning.hpp: This file contains the definition of the SemanticWarning class, which is used to handle semantic warnings in the compiler.

#pragma once
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

class SemanticWarning : public std::runtime_error {
public:
    int line;

    SemanticWarning(const std::string& msg, int ln);
    // 儲存所有警告
    static std::vector<std::pair<int, std::string>> warnings;

    // 是否有警告
    static bool hasWarning();

    // 列印所有警告
    static void printAllWarning();

    // 清除警告
    static void clearWarning();
};