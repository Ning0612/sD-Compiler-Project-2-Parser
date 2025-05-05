# ────────────── Toolchain ──────────────
CXX   = g++
LEX   = flex
YACC  = bison

# ────────────── Flags ──────────────────
CXXFLAGS  = -std=c++17 -Wall -Wextra -pedantic -I./src
YACCFLAGS = -y -d

# ────────────── Directories ────────────
SRC_DIR  = src
BUILD_DIR = build
BIN_DIR = bin

# ────────────── Files ──────────────────
OBJS = \
  $(BUILD_DIR)/y.tab.o \
  $(BUILD_DIR)/lex.yy.o \
  $(BUILD_DIR)/sem_utils.o \
  $(BUILD_DIR)/sd_types.o \
  $(BUILD_DIR)/symtab.o

TARGET = $(BIN_DIR)/sd

# ────────────── Rules ──────────────────
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generate parser
$(SRC_DIR)/y.tab.cpp $(SRC_DIR)/y.tab.hpp: $(SRC_DIR)/p2_parser.y
	$(YACC) $(YACCFLAGS) -o $@ $<

# Generate scanner
$(SRC_DIR)/lex.yy.cpp: $(SRC_DIR)/p2_lex.l $(SRC_DIR)/y.tab.hpp
	$(LEX) --outfile=$@ $<

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test file default use test.sd.txt
test: $(TARGET)
	@echo "=== Running test.sd.txt ==="
	$(TARGET) input/test.sd.txt

# Test file with custom name
runtest: $(TARGET)
	@echo "=== Running $(TEST) ==="
	$(TARGET) $(TEST)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(SRC_DIR)/lex.yy.cpp $(SRC_DIR)/y.tab.*

.PHONY: all clean
