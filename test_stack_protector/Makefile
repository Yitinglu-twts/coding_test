CC := gcc
CFLAGS := -g -Wall -O0 -std=c99
CFLAGS += -fstack-protector-all
#CFLAGS += -fno-stack-protector

SRCS := main.c
OBJS := $(patsubst %.c, %.o, $(SRCS))

Target := test

test : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm *.o -f
	rm $(Target) -f