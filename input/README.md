# sD Test Cases Overview

This document summarizes the purpose and semantic checks performed by each individual test case file used for validating the `sD` language compiler frontend. Each `.sd` file focuses on a specific language feature or group of related semantic rules.

---

## 📄 case1.sd – Constant Folding, Type Conversion, String Operations, Division-by-Zero

### 🔍 Covered Concepts:
- **Constant Folding**
  - Compile-time evaluation of integer, float, double, boolean, and string expressions
- **Implicit Conversions**
  - `double → float`, `float → int`, and warnings for narrowing
- **String Concatenation**
  - Compile-time string expression folding
- **Division/Modulus by Zero**
  - Compile-time detection of illegal divisions and modulus operations

### 🛑 Errors/Warnings Tested:
- Warning for implicit narrowing conversions (e.g., double → float)
- Error for division/modulus by constant zero
- Correct handling of runtime-only division checks

---

## 📄 case2.sd – Array Declarations and Indexing

### 🔍 Covered Concepts:
- **Array Declarations**
  - Constant integer expressions as array sizes
  - Multi-dimensional array declaration
- **Array Reference Validation**
  - Index type and bounds checking
  - Constant out-of-bound access
  - Deferred runtime checks for variable indices

### 🛑 Errors/Warnings Tested:
- Invalid array sizes: zero, negative, non-integer
- Index type mismatch (e.g., using string as index)
- Compile-time out-of-bounds errors

---

## 📄 case3.sd – Loop Constructs

### 🔍 Covered Concepts:
- **Loop Types**
  - `for`, `foreach`, and `do-while` support
- **Complex Loop Headers**
  - Multiple initialization and update expressions in `for` loops
- **Foreach Range Validation**
  - Constant expression evaluation for range bounds

### 🛑 Errors/Warnings Tested:
- `foreach` with invalid range (start == end)
- Full-loop coverage including `print` side effects

---

## 📄 case4.sd – Functions, Type Checking, Name Conflicts

### 🔍 Covered Concepts:
- **Function Definitions and Calls**
  - Argument type and count matching
  - Return value type validation
- **Array as Function Parameters**
  - Ensures fixed-size array parameter types match
- **Implicit Conversion Handling**
  - In parameter passing and assignment
- **Name Conflict Checks**
  - Conflicting declarations (e.g., variable vs. function)

### 🛑 Errors/Warnings Tested:
- Calling function with incorrect argument types
- Using incorrect return value type
- Redeclaring a function name as a variable (illegal)

---

## ✅ Usage

Each file can be compiled and tested independently:
```bash
./sc case1.sd
./sc case2.sd
./sc case3.sd
./sc case4.sd
