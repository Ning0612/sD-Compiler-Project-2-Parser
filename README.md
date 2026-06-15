
---


# sD Compiler Parser

This project implements a front-end compiler for a custom C-like language called **sD**, designed for educational compiler construction. The compiler performs **lexical analysis**, **parsing**, and **semantic analysis**, including type checking, constant folding, and error detection.

---

## 📁 Project Structure
```
.
├── Makefile                # Build script
├── bin/sd                 # Final executable
├── build/                 # Object files and intermediates
├── src/                   # Compiler source code (scanner, parser, analyzer)
├── input/                 # Test case programs (.sd)
│   ├── case1.sd           # Test: constant folding & errors
│   ├── case2.sd           # Test: array declaration/index
│   ├── case3.sd           # Test: loop syntax
│   ├── case4.sd           # Test: functions & type checks
```

---

## 🔧 Build Instructions

To compile the project:

```bash
make
````

To run the compiler on a `.sd` file:

```bash
./bin/sd input/case1.sd
```

---

## ✅ Supported Language Features

### Basic Types

* `int`, `float`, `double`
* `bool`, `string`
* Fixed-size `array`

### Statements

* Variable/constant declarations
* `if`, `if-else`, `while`, `do-while`, `for`, `foreach`
* `print`, `println`, `read`, `return`

### Expressions

* Arithmetic: `+`, `-`, `*`, `/`, `%`
* Logic: `!`, `&&`, `||`
* Comparison: `<`, `>`, `==`, `!=`, etc.
* String concatenation (`+`)
* Constant folding at compile-time

### Functions

* Return values & parameter type checking
* Array parameter passing
* Function calls with argument validation

---

## 🧪 Test Case Overview

All test files are under `input/`. Each file tests distinct semantic areas:

### `case1.sd` – Constant Expressions & Folding

* Compile-time evaluation of numeric/boolean/string expressions
* Implicit type conversions
* Division/modulus by zero (compile-time detection)

### `case2.sd` – Array Semantics

* Array declaration (valid/invalid size)
* Multidimensional array access
* Index type and bounds checking

### `case3.sd` – Loops & Foreach

* `for`, `do-while`, `foreach` usage
* Valid/invalid foreach range (start must be less than end)
* Multiple loop variables

### `case4.sd` – Function Semantics

* Return type validation
* Argument type/count checking
* Array parameter dimensions
* Name conflicts (e.g., variable name same as function)

---

## ⚠️ Semantic Checks Performed

* ❌ Type mismatches (assignment, function call, return)
* ❌ Division by constant zero
* ❌ Redeclaration errors
* ❌ Illegal conversions (with warnings for implicit cast)
* ❌ Invalid array accesses or dimensions
* ❌ Conflicting names (function vs. variable)
* ⚠️ Implicit type conversion warnings
* ✅ Constant folding and propagation

---

## 📌 Known Limitations

* No code generation or runtime execution
* Runtime array bounds are not checked
* No type inference; all types must be explicit

---

## ✍️ Authors & Acknowledgements

Developed for \[Compiler Project 2], Department of Computer Science NTUST, Spring 2025.
Author: \[Ning / B11110524]

---

