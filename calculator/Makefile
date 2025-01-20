CC = gcc
CFLAGS = -lm

YACCFILE = calculator.y
LEXFILE = calculator.l
OUTPUTFILE = calculator

PARSERHEADER = calculator.tab.h
PARSERCFILE = calculator.tab.c 
FLEX = lex.yy.c

all : $(OUTPUTFILE)


$(OUTPUTFILE) : $(PARSERCFILE) $(FLEX)
	$(CC) $(CFLAGS) -o $@ $^

$(PARSERCFILE) $(PARSERHEADER) : $(YACCFILE)
	bison -d $(YACCFILE)

$(FLEX) : $(LEXFILE)
	flex $(LEXFILE)

run : $(OUTPUTFILE)
	./$(OUTPUTFILE)

clean :
	rm -f $(OUTPUTFILE) $(PARSERHEADER) $(PARSERCFILE) $(FLEX)

