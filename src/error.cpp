// error.cpp: This file contains the implementation of the SemanticError class, which is used to handle semantic errors in the compiler.
#include "error.hpp"

// SemanticError: Semantic error during compilation
//   - msg: error message
//   - line: line number where the error occurred
//   - This exception is thrown when a semantic error is detected in the code.
//   - It inherits from std::runtime_error to provide a standard error handling mechanism.
// Constructor for SemanticError
// Takes a message and line number as parameters
// Initializes the base class std::runtime_error with the message
// Sets the line number for the error
SemanticError::SemanticError(const std::string& msg, int ln)
    : std::runtime_error(msg), line(ln) {}
