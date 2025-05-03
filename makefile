# ---- 原本是 gcc / cc ----
CC      = g++
LEX     = flex          # flex → lex.yy.c
YACC    = bison -y -d   # -y 產生 y.tab.c, y.tab.h
CFLAGS  = -std=c++17 -Wall -Wextra -O2
LDFLAGS = -lfl          # flex run‑time；若用 -lfl 找不到，改 -llex

all: sd

sd: lex.yy.o y.tab.o main.o symbol.o
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o lex.yy.c y.tab.* sd
