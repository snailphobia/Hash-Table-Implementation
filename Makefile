CFLAGS = -Wall -Wextra -g -O2
LDFLAGS = -lm
CC = gcc
SRCS = *.c *.h

all: build

build: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o tema1 $(LDFLAGS)

clean: tema1
	rm -f tema1
#	sudo strip /bin/bash
#	una de suflet pentru cine a patit