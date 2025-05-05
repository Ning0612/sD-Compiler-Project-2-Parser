# ────────────── Tool chain ──────────────
CXX   = g++           # 或 clang++
LEX   = flex
YACC  = bison         # -y: 與傳統 yacc 相容

# ────────────── Flags ───────────────────
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
LEXFLAGS =
YACCFLAGS = -y -d     # -d 產生 y.tab.hpp 給 scanner 用

# ────────────── Object list ─────────────
OBJ = y.tab.o lex.yy.o sd_common.o

# ────────────── Default target ──────────
all: sd

# ────────────── 產生 parser (Bison) ─────
# 會輸出 y.tab.cpp / y.tab.hpp
y.tab.cpp y.tab.hpp: p2_parser.y
	$(YACC) $(YACCFLAGS) -o y.tab.cpp $<

# ────────────── 產生 scanner (Flex) ─────
# 依賴 y.tab.hpp 取得 token 定義
lex.yy.cpp: p2_lex.l y.tab.hpp
	$(LEX) --outfile=$@ $<

# ────────────── 編譯物件檔 ──────────────
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# ────────────── 連結 ───────────────────
sd: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: sd
	@echo "=== 測試 ==="
	./sd HelloWorld.sd.txt

# ────────────── 其他目標 ────────────────
clean:
	rm -f sd lex.yy.cpp y.tab.* *.o
.PHONY: all clean
