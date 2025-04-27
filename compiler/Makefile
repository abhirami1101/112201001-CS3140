CC = gcc
CFLAGS = -lm

YACCFILE = src/compiler.y
LEXFILE = src/compiler.l
OUTPUTFILE = bin/compiler
SYMBOL_TABLE = src/symbol_table.c src/codegen.c
TREE = src/tree.c
BIN = bin

PARSERHEADER = y.tab.h
PARSERCFILE = y.tab.c 
FLEX = lex.yy.c

all : $(OUTPUTFILE)


$(OUTPUTFILE) : $(PARSERCFILE) $(FLEX) $(SYMBOL_TABLE) $(TREE)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

$(PARSERCFILE) $(PARSERHEADER) : $(YACCFILE)
	yacc -d $(YACCFILE)

debug : $(OUTPUTFILE)
	lldb ./$(OUTPUTFILE)  # Start the debugger with the compiled binary

$(FLEX) : $(LEXFILE)
	flex $(LEXFILE)

run : $(OUTPUTFILE)
	./$(OUTPUTFILE)

clean :
	rm -f $(OUTPUTFILE) $(PARSERHEADER) $(PARSERCFILE) $(FLEX)
	rm -f bin/*.s