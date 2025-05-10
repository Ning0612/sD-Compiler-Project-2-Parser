
---

# README - P1 到 P2 Scanner 的變更說明

## 簡介

此專案的 P2 版本是基於 P1 的 lexical analyzer，主要將程式語言由 **C 改為 C++**，並配合語意分析與 parser 整合，進行以下修改：

## 主要變更

### 1. **語言從 C 移到 C++**

* 使用 `#include <cstdio>` 和 `#include <cstdlib>` 取代 `stdio.h` 和 `stdlib.h`
* 移除 C-style 的結構與 symbol table 管理邏輯
* 改用 `sem_utils.hpp` 與 `y.tab.hpp`，與 C++ 語意分析模組整合

### 2. **引入 Lex options**

* 新增：

  ```lex
  %option noyywrap nodefault
  %option yylineno
  ```

  * 支援自動行號與簡化 wrapper 設定

### 3. **Debug 模式條件化**

* 所有 debug 輸出（如 `token()` 巨集）包進 `#ifdef DEBUG_LEX` 中，方便開關控制

### 4. **移除 symbol table 處理邏輯**

* P1 中原有的 symbol table 結構與雜湊管理程式碼已全數移除
* P2 時僅負責進行 token 的識別與回傳，symbol table 留給語意分析階段處理，並重新定義 symbol table 

---