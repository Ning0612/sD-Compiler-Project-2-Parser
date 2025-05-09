#pragma once
#include <stdexcept>
#include <string>

struct SemanticError : public std::runtime_error {
    int line;
    SemanticError(const std::string& msg, int ln): std::runtime_error(msg), line(ln) {}
};