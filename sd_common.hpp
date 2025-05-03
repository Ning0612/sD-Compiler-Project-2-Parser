#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <stdexcept>

/* ───── 型別系統 ───── */
enum class BaseKind { Int, Float, Bool, String, Void };

struct Type {
    BaseKind  base;
    int dim = 0;            // 0 = scalar
    std::vector<int> sizes;                  // 每維大小
    std::vector<std::shared_ptr<Type>> params; // 函式參數
    std::shared_ptr<Type> ret;               // 函式回傳型別

    /* 陣列 / 函式 建構子 */
    static std::shared_ptr<Type> array(std::shared_ptr<Type> elem, std::vector<int> sz);
    static std::shared_ptr<Type> func(std::shared_ptr<Type> ret, std::vector<std::shared_ptr<Type>> ps);

    bool isArray()   const { return dim > 0; }
    bool isFunc()    const { return !params.empty() || ret; }
    bool operator==(const Type& rhs) const;
    bool operator!=(const Type& rhs) const { return !(*this == rhs); }
};

/* ───── 符號表 ───── */
struct Symbol {
    std::string name;
    std::shared_ptr<Type> type;
    bool isConst;
};

class SymbolTable {
public:
    void  enterScope();                 // push
    void  leaveScope();                 // pop
    bool  insert(const Symbol& s);      // false = 已存在同名
    Symbol* lookup(const std::string&); // 最近一層
    Symbol* lookupGlobal(const std::string&);

private:
    using Bucket = std::unordered_map<std::string, Symbol>;
    std::vector<Bucket> scopes { 1 };   // scopes[0] = global
};

/* ───── 語意錯誤 ───── */
class SemanticError : public std::runtime_error {
public:
    explicit SemanticError(const std::string& msg, int line);
    int line() const noexcept { return lineNo; }
private:
    int lineNo;
};
