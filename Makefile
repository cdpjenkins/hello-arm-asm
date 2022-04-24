OBJS = hello.o main.o find_max.o hailstone.s
CFLAGS = -g -O3

all: hello

clean:
	rm hello *.o

hello: $(OBJS)
	gcc -o hello $(OBJS) -lgcc

%.o: %.s *.h
	as -g -o $@ $<

main.o: main.c
	gcc $(CFLAGS) -c main.c

