OBJS = main.o 
CFLAGS = -g -O3

all: main

clean:
	rm main *.o

hello: $(OBJS)
	gcc -o main $(OBJS)

%.o: %.s *.h
	as -g -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c $<
