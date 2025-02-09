CC = gcc
CFLAGS = -lm

YACCFILE = src/compiler.y
LEXFILE = src/compiler.l
OUTPUTFILE = bin/compiler
SYMBOL_TABLE = src/symbol_table.c
TREE = src/tree.c

PARSERHEADER = y.tab.h
PARSERCFILE = y.tab.c 
FLEX = lex.yy.c

all : $(OUTPUTFILE)


$(OUTPUTFILE) : $(PARSERCFILE) $(FLEX) $(SYMBOL_TABLE) $(TREE)
	$(CC) $(CFLAGS) -o $@ $^

$(PARSERCFILE) $(PARSERHEADER) : $(YACCFILE)
	yacc -d $(YACCFILE)

$(FLEX) : $(LEXFILE)
	flex $(LEXFILE)

run : $(OUTPUTFILE)
	./$(OUTPUTFILE)

clean :
	rm -f $(OUTPUTFILE) $(PARSERHEADER) $(PARSERCFILE) $(FLEX)