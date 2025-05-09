# ────────────── Toolchain ──────────────
CXX   = g++
LEX   = flex
YACC  = bison

# ────────────── Flags ──────────────────
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Wno-unused-function -pedantic -I./src
YACCFLAGS = -y -d

# ────────────── Directories ────────────
SRC_DIR   = src
BUILD_DIR = build
BIN_DIR   = bin

# ────────────── Files ──────────────────
OBJS = \
  $(BUILD_DIR)/y.tab.o \
  $(BUILD_DIR)/lex.yy.o \
  $(BUILD_DIR)/sem_utils.o \
  $(BUILD_DIR)/sd_types.o \
  $(BUILD_DIR)/symtab.o \
  $(BUILD_DIR)/error.o \
  $(BUILD_DIR)/var_init.o \
  $(BUILD_DIR)/expr.o 

TARGET = $(BIN_DIR)/sd

# ────────────── Targets ────────────────
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ────────────── Parser & Scanner ───────
$(SRC_DIR)/y.tab.cpp $(SRC_DIR)/y.tab.hpp: $(SRC_DIR)/p2_parser.y
	$(YACC) $(YACCFLAGS) -o $(SRC_DIR)/y.tab.cpp $<

$(SRC_DIR)/lex.yy.cpp: $(SRC_DIR)/p2_lex.l $(SRC_DIR)/y.tab.hpp
	$(LEX) --outfile=$@ $<

# ────────────── Conflict Check ──────────────
checkconflict:
	$(YACC) $(YACCFLAGS) -v -o $(SRC_DIR)/y.tab.cpp $(SRC_DIR)/p2_parser.y
	@echo "=== Conflicts Report ==="
	@if grep -q 'conflict' y.output; then \
		grep 'conflict' y.output; \
	else \
		echo "No shift/reduce or reduce/reduce conflicts found."; \
	fi

# ────────────── Compilation Rules ──────
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ────────────── Testing ────────────────
test: $(TARGET)
	@echo "=== Running test.sd.txt ==="
	$(TARGET) input/test.sd.txt

runtest: $(TARGET)
ifndef TEST
	$(error Please specify TEST=filename)
endif
	@echo "=== Running $(TEST) ==="
	$(TARGET) $(TEST)

# ────────────── Clean ──────────────────
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(SRC_DIR)/lex.yy.cpp $(SRC_DIR)/y.tab.*

.PHONY: all clean test runtest
