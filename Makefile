CC = gcc
TARGET = Reduced_C_Compier
OBJS = kim.tab.c lex.yy.c print.c main.c funs.c semantic.c print_sem.c gen.c
CFLAGS = -w -g

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

lex.yy.c : kim.l
	flex kim.l

kim.tab.c : kim.y
	bison -d kim.y

clean :
	rm -f lex.yy.c
	rm -f kim.tab.c
	rm -f $(TARGET)