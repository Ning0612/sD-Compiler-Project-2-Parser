// sd_types.hpp
#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <cstddef>

// Basic built-in types
enum BaseKind { BK_Int, BK_Float, BK_Double, BK_Bool, BK_String, BK_Void };

// Type compatibility and promotion utilities
bool isConvertible(BaseKind a, BaseKind b);
bool isBaseCompatible(BaseKind a, BaseKind b);
BaseKind promote(BaseKind b1, BaseKind b2);
std::string baseKindToStr(BaseKind kind);

// Type information structure
struct Type {
    BaseKind base;
    int dim;                        // dimension (0 for scalar)
    std::vector<int> sizes;         // array dimensions
    std::vector<Type*> params;      // function parameter types
    Type* ret;                      // function return type

    explicit Type(BaseKind b);
    bool isScalar() const;
    bool isArray() const;
    bool isFunc() const;

    bool operator==(const Type& o) const;
    bool operator!=(const Type& o) const;
    bool isCompatibleWith(const Type& o) const;

    void dbgPrint() const;          // Debug print
};

// Hash function for Type
struct TypeHash {
    std::size_t operator()(const Type& t) const;
};

// Memory arena for creating and caching unique Type instances
class TypeArena {
public:
    ~TypeArena();
    Type* make(BaseKind kind);
    Type* makeArray(Type* elem, const std::vector<int>& sizes);
    Type* makeFunc(Type* ret, const std::vector<Type*>& params);

private:
    std::vector<Type*> types;
    std::unordered_map<Type, Type*, TypeHash> cache;
};
