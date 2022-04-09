CC := gcc
CFLAGS := -g -Wall
LDFLAGS :=

SRCS := main.c
OBJS := $(patsubst %.c,%.o,$(SRCS))

all:

.PHONY: clean check


check:
	@./env_check.sh && echo "success"

clean:
	rm -f $(OBJS)