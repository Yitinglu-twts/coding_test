CC := gcc
CFLAGS := -g -Wall -finstrument-functions

SRCS := main.c \
		task.c
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