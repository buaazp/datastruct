.PHONY: clean
CC = gcc
CFLAGS = -g -ggdb3
PROJECT = testsqlist
SRCS = sqlist testsqlist
OBJS = $(addsuffix .o, $(SRCS))

$(PROJECT) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROJECT)

%.o : %.c defaultvar.h
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm $(PROJECT) $(OBJS)
