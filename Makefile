all: hello

clean:
	rm hello hello.o

hello: hello.o main.o
	gcc -o hello hello.o main.o -lgcc

hello.o: hello.s
	as -g -o hello.o hello.s	

main.o: main.c
	gcc -g -c main.c

