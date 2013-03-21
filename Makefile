.PHONY: clean
CC = gcc
CFLAGS = -g -ggdb3
PROJECT = all
MODULES = testsqlist testlnode
SRCS = sqlist testsqlist lnode testlnode
OBJS = $(addsuffix .o, $(SRCS))

$(PROJECT) : $(MODULES)
.PHONY : $(PROJECT)

testsqlist : sqlist.o testsqlist.o
	$(CC) $(CFLAGS) sqlist.o testsqlist.o -o testsqlist

testlnode : lnode.o testlnode.o
	$(CC) $(CFLAGS) lnode.o testlnode.o -o testlnode

%.o : %.c defaultvar.h
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm $(MODULES) $(OBJS)
