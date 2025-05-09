#pragma once

#include "var_init.hpp"
#include "error.hpp"
#include "expr.hpp"
#include "sd_types.hpp"
#include "symtab.hpp"

/*─────────────── Type Conversion ───────────────*/
// Convert constant expressions to raw base types
int toInt(const ExprInfo e);
float toFloat(const ExprInfo e);
double toDouble(const ExprInfo e);
bool toBool(const ExprInfo e);
std::string toString(const ExprInfo e);

/*─────────────── Operators ─────────────────────*/
enum NumOp { OPADD, OPSUB, OPMUL, OPDIV, OPMOD };
enum RelOp { OPLT, OPLE, OPGT, OPGE };

// Convert enum to operator symbol string
std::string numOpToStr(NumOp op);
std::string relOpToStr(RelOp op);

/*─────────────── Expression Evaluation ─────────*/
// Concatenates two string expressions
ExprInfo* concatStringResult(const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Arithmetic operation (+ - * / %) with type promotion and constant folding
ExprInfo* numericOpResult(NumOp op, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Relational comparison (< <= > >=) with constant folding
ExprInfo* relOpResult(RelOp op, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Equality comparison (== !=) with constant folding
ExprInfo* eqOpResult(bool equal, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Logical and/or expression (&& ||)
ExprInfo* boolOpResult(bool isAnd, const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno);

// Logical not expression (!)
ExprInfo* notOpResult(const ExprInfo& expr, TypeArena& pool, int lineno);

// Unary plus/minus (+x / -x)
ExprInfo* unaryOpResult(bool isMinus, const ExprInfo& expr, int lineno);

// Handle array indexing expressions
ExprInfo* resolveArrayAccess(const std::string& id, TypeArena& typePool, SymbolTable& symTab, const std::vector<int>& arrayIndex, int lineno);

/*─────────────── Semantic Checks ───────────────*/
// Ensure the expression is a boolean scalar (used in if, while, etc.)
void checkBoolExpr(const std::string& context, const ExprInfo& expr, int lineno);

// Check if increment/decrement operation is valid on the given lvalue
void checkIncDecValid(const std::string& op, const ExprInfo& expr, int lineno);

// Check if foreach range values are valid (both must be constant int scalars, from < to)
void checkForeachRange(const ExprInfo& from, const ExprInfo& to, int lineno);

// Extract array index value if constant, return 0 otherwise
int extractArrayIndexOrZero(const ExprInfo& expr, int lineno);

// Ensure the given expression is a positive constant integer for array dimension
int checkArrayDimExpr(const ExprInfo& expr, int lineno);

// Check if foreach loop index is declared and of int type
void checkForeachIndex(Symbol* sym, int lineno);

// Validate variable declaration (check redeclaration, conflict with functions, etc.)
void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno);

/*─────────────── Function Handling ─────────────*/
// Declare a function in the symbol table and enter its parameter scope
void declareFunction(const std::string& name, Type* returnType, const std::vector<Symbol>& paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno);

// Check function call correctness: existence, parameter count and type compatibility
void checkFuncCall(Symbol* symbol, const std::string& name, const std::vector<ExprInfo>& args, int lineno);

/*─────────────── Variable / Const Check ─────────*/
// Check if an assignment is valid between types
void checkAssignment(const ExprInfo& target, const ExprInfo& value, int lineno);

// Validate whether the expression is allowed to be printed (no arrays/functions/void)
void checkPrint(const ExprInfo& expr, int lineno);

// Validate whether the expression is a valid target for read operation
void checkRead(const ExprInfo& expr, int lineno);

// Handle multiple variable declarations, check type compatibility and duplicates
void tryDeclareVarables(SymbolTable& symTab, TypeArena& typePool, std::vector<VarInit>& varInits, Type* type, int lineno);

// Declare a constant, verify value is valid and insert into symbol table
void tryDeclareConstant(SymbolTable& symTab, std::string& id, Type* type, const ExprInfo& value, int lineno);
