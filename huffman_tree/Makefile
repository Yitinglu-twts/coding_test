CC := gcc
CFLAGS := -g -Wall
AddrSanitizer := -fsanitize=address
LDFLAGS :=

SRCS := main.c \
		ascii_tbl_mgt.c

OBJS := $(patsubst %.c,%.o, $(SRCS))
DEPS := $(OBJS:%.o=%.dep)

TARGET := human_tree

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(AddrSanitizer) $(OBJS)  -o $(TARGET)

.PHONY: test
test:
	@echo OBJS = $(OBJS)
	@echo DEPS = $(DEPS)
	@echo PID = $$$$



%.o:%.c
	$(CC) $(CFLAGS) $(AddrSanitizer) -c $< -MMD

%.dep:%.d
	mv $< $@

-include $(DEPS)

.PHONY: clean
clean:
	rm -f *.o  *.d $(TARGET)