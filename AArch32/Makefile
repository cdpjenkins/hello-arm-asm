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
# The gcc-10-arm-linux-gnueabihf toolchain in Raspbian 64 bit  appears to generate Thumb binaries by
# default unless you tell it otherwise. I have no idea why this is.
CFLAGS = -g -O2 -marm

all: hello

clean:
	rm hello *.o

hello: $(OBJS)
	$(CC) -o hello $(OBJS) -lgcc

%.o: %.s *.h
	$(AS) -g -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

