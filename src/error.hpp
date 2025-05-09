// error.hpp: This file contains the definition of the SemanticError class, which is used to handle semantic errors in the compiler.
#pragma once
#include <stdexcept>
#include <string>

// SemanticError: Semantic error during compilation
//   - msg: error message
//   - line: line number where the error occurred
//   - This exception is thrown when a semantic error is detected in the code.
//   - It inherits from std::runtime_error to provide a standard error handling mechanism.
struct SemanticError : public std::runtime_error {
    int line;
    SemanticError(const std::string& msg, int ln);
};
