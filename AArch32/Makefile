UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
	TOOLCHAIN_PREFIX=arm-linux-gnueabihf
endif
ifeq ($(UNAME),Darwin)
	TOOLCHAIN_PREFIX=armv8-rpi3-linux-gnueabihf
endif

CC = $(TOOLCHAIN_PREFIX)-gcc
AS = $(TOOLCHAIN_PREFIX)-as
OBJS = hello.o main.o find_max.o hailstone.s
CFLAGS = -g -O3

all: hello

clean:
	rm hello *.o

hello: $(OBJS)
	$(CC) -o hello $(OBJS) -lgcc

%.o: %.s *.h
	$(AS) -g -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

