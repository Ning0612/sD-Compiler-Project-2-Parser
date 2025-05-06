#pragma once
#include "sd_types.hpp"
#include <stdexcept>
#include <string>

/*───────── 常數 / 值 描述 ─────────*/
enum ValueKind { VK_None, VK_Int, VK_Float, VK_Bool, VK_String };

struct ExprInfo {
    Type*     type;
    bool      isConst;
    ValueKind valueKind;

    union { int iVal; float fVal; bool bVal; };
    std::string sVal;

    explicit ExprInfo(Type* t, bool c=false)
        : type(t), isConst(c), valueKind(VK_None) {}

    /* setter */
    void setInt   (int v)             { valueKind=VK_Int;   iVal=v; isConst=true; }
    void setFloat (float v)           { valueKind=VK_Float; fVal=v; isConst=true; }
    void setBool  (bool v)            { valueKind=VK_Bool;  bVal=v; isConst=true; }
    void setString(const std::string& s){ valueKind=VK_String; sVal=s; isConst=true; }

    /* zero 判斷，僅對常數數值有意義 */
    bool isZeroValue() const {
        if(!isConst) return false;
        switch(valueKind){
            case VK_Int:   return iVal==0;
            case VK_Float: return fVal==0.0f;
            case VK_Bool:  return bVal==false;
            default:       return false;
        }
    }

    /* getter（型別不符丟例外）*/
    int    getInt()    const { if(valueKind!=VK_Int)   throw std::runtime_error("not int");   return iVal; }
    float  getFloat()  const { if(valueKind!=VK_Float) throw std::runtime_error("not float"); return fVal; }
    bool   getBool()   const { if(valueKind!=VK_Bool)  throw std::runtime_error("not bool");  return bVal; }
    std::string getString() const{ if(valueKind!=VK_String) throw std::runtime_error("not string"); return sVal; }
    void setConstValueFromExpr(const ExprInfo* e) {
        switch (e->valueKind) {
            case VK_Int: setInt(e->getInt()); break;
            case VK_Float: setFloat(e->getFloat()); break;
            case VK_Bool: setBool(e->getBool()); break;
            case VK_String: setString(e->getString()); break;
            default: break;
        }
    }

};
