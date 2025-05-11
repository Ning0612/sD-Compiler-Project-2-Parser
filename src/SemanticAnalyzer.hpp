#pragma once

#include "VarInit.hpp"
#include "SemanticError.hpp"
#include "SemanticWarning.hpp"
#include "SymbolTable.hpp"
#include "ExprInfo.hpp"
#include "SdTypes.hpp"

/* ─────────────── Value Extraction ─────────────── */

// Convert expression value to int (for const expr)
int toInt(const ExprInfo e);

// Convert expression value to float (for const expr)
float toFloat(const ExprInfo e);

// Convert expression value to double (for const expr)
double toDouble(const ExprInfo e);

// Convert expression value to bool (for const expr)
bool toBool(const ExprInfo e);

// Convert expression value to string (for const expr)
std::string toString(const ExprInfo e);

/* ─────────────── Operator Types ─────────────── */

enum NumOp { OPADD, OPSUB, OPMUL, OPDIV, OPMOD }; // Numeric ops
enum RelOp { OPLT, OPLE, OPGT, OPGE };            // Relational ops

std::string numOpToStr(NumOp op); // Return string form of numeric op
std::string relOpToStr(RelOp op); // Return string form of relational op

/* ─────────────── Expression Evaluation ─────────────── */

// Handle string concatenation (+ operator between strings)
ExprInfo* concatStringResult(const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Evaluate numeric binary operations (e.g., +, -, *, /)
ExprInfo* numericOpResult(NumOp op, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Evaluate relational binary operations (e.g., <, >=)
ExprInfo* relOpResult(RelOp op, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Evaluate equality/inequality (==, !=)
ExprInfo* eqOpResult(bool equal, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Evaluate boolean binary operations (&&, ||)
ExprInfo* boolOpResult(bool isAnd, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Evaluate unary logical NOT (!)
ExprInfo* notOpResult(const ExprInfo& expr, TypeArena& pool, int lineno);

// Evaluate unary + or - (sign operator)
ExprInfo* unaryOpResult(bool isMinus, const ExprInfo& expr, int lineno);

// Handle array access (e.g., arr[2][3])
ExprInfo* resolveArrayAccess(const std::string& id, TypeArena& typePool, SymbolTable& symTab, const std::vector<int>& arrayIndex, int lineno);

/* ─────────────── Semantic Checks ─────────────── */

// Ensure an expression is boolean in a given context (if, while, etc.)
void checkBoolExpr(const std::string& context, const ExprInfo& expr, int lineno);

// Validate ++ or -- target is modifiable and not const
void checkIncDecValid(const std::string& op, const ExprInfo& expr, int lineno);

// Validate foreach range (start..end)
void checkForeachRange(const ExprInfo& from, const ExprInfo& to, int lineno);

// Ensure foreach index is declared and mutable
void checkForeachIndex(Symbol* sym, int lineno);

// Extract int index from an array subscript expression
int extractArrayIndexOrZero(const ExprInfo& expr, int lineno);

// Check array dimension value is valid and constant
int checkArrayDimExpr(const ExprInfo& expr, int lineno);

/* ─────────────── Declarations and Checks ─────────────── */

// Try inserting a variable symbol into current scope
void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno);

// Declare a new function and insert into symbol table
void declareFunction(const std::string& name, Type* returnType, const std::vector<Symbol>& paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno);

// Check function call is valid (existence, args match)
bool checkFuncCall(Symbol* symbol, const std::string& name, const std::vector<ExprInfo>& args, int lineno);

// Check if assignment is valid (type compatibility)
void checkAssignment(const ExprInfo& target, const ExprInfo& value, int lineno);

// Check if expression is printable (valid type)
void checkPrint(const ExprInfo& expr, int lineno);

// Check if expression is readable (i.e., writable location)
void checkRead(const ExprInfo& expr, int lineno);

// Try declaring a list of variables (normal or arrays)
void tryDeclareVarable(SymbolTable& symTab, TypeArena& typePool, const VarInit& varInit, Type* type, int lineno);

// Try declaring a constant (must have a literal value)
void tryDeclareConstant(SymbolTable& symTab, std::string& id, Type* type, const ExprInfo& value, int lineno);
