CC := gcc
CFLAGS := -g -Wall
INC := -I.
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
	@echo foo = $(foo)


POSTCOMPILE :=
%.o: %.c %.dep
	$(CC) $(CFLAGS) $(INC) $(AddrSanitizer) -c $< -MMD -MP -MF $*.dep
	$(POSTCOMPILE)


%.dep:;


-include $(DEPS)

.PHONY: clean
clean:
	rm -f *.o  *.dep $(TARGET)