CC = gcc
CFLAGS = -g
SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=.out)
.SECONDARY:
all: $(TARGETS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.out: %.o
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f *.out *.o