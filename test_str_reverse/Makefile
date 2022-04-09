CC := gcc
CFLAGS := -Wall -O0 -std=c99

SRCS := main.c
OBJS := $(patsubst %.c, %.o, $(SRCS))

all := test

test : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm *.o -f
	rm $(all) -f