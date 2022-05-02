OBJS=boot.o uart.o main.o
CFLAGS=-O3

all: kernel8.img

clean:
	rm -f *.o kernel kernel8.img

kernel8.img: kernel
	aarch64-unknown-linux-gnu-objcopy -O binary kernel kernel8.img

kernel: $(OBJS)
	aarch64-unknown-linux-gnu-ld -nostdlib -T link.lds -o kernel $(OBJS)

%.o: %.s
	aarch64-unknown-linux-gnu-gcc -c $< -o $@

%.o: %.c
	aarch64-unknown-linux-gnu-gcc $(CFLAGS)  -c $< -o $@
