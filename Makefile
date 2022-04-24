OBJS = hello.o main.o find_max.o

all: hello

clean:
	rm hello *.o

hello: $(OBJS)
	gcc -o hello $(OBJS) -lgcc

hello.o: hello.s
	as -g -o hello.o hello.s

%.o: %.s *.h
	as -g -o $@ $<


main.o: main.c
	gcc -g -c main.c

