# ────────────── Tool chain ──────────────
CXX   = g++          # 或 clang++
LEX   = flex
YACC  = bison        # -y: 與傳統 yacc 相容

# ────────────── Flags ───────────────────
CXXFLAGS  = -std=c++17 -Wall -Wextra -pedantic
LEXFLAGS  =
YACCFLAGS = -y -d    # 產生 y.tab.hpp 給 scanner 使用

# ────────────── Source / Object list ────
SRCS_CORE = sd_types.cpp symtab.cpp sem_utils.cpp
OBJS_CORE = $(SRCS_CORE:.cpp=.o)

# Bison / Flex 產生的檔案
PARSER_SRC = y.tab.cpp
SCAN_SRC   = lex.yy.cpp
PARSER_OBJ = y.tab.o
SCAN_OBJ   = lex.yy.o

# 最終物件檔
OBJ = $(OBJS_CORE) $(PARSER_OBJ) $(SCAN_OBJ)

# ────────────── Targets ─────────────────
all: sd

# 產生 parser
$(PARSER_SRC) y.tab.hpp: p2_parser.y
	$(YACC) $(YACCFLAGS) -o $(PARSER_SRC) $<

# 產生 scanner
$(SCAN_SRC): p2_lex.l y.tab.hpp
	$(LEX) --outfile=$@ $<

# 編譯核心 .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# 編譯 Bison/Flex 產生的 .cpp
$(PARSER_OBJ): $(PARSER_SRC)
	$(CXX) $(CXXFLAGS) -c $<

$(SCAN_OBJ): $(SCAN_SRC)
	$(CXX) $(CXXFLAGS) -c $<

# 連結
sd: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 測試範例（可自行更換檔名）
test: sd
	@echo "=== Running sample ==="
	./sd HelloWorld.sd.txt

# 清理
clean:
	$(RM) sd $(OBJ) $(PARSER_SRC) y.tab.hpp $(SCAN_SRC)

.PHONY: all test clean
