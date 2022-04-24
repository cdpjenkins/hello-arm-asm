OBJS = main.o identity.o
CFLAGS = -g -O3

all: main

clean:
	rm main *.o

main: $(OBJS)
	gcc -o main $(OBJS)

%.o: %.s *.h
	as -g -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c $<
