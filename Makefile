CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

hsh: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) hsh
