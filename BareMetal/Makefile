OBJS=boot.o main.o lib.o uart.o

all: kernel8.img

clean:
	rm -f *.o kernel kernel8.img

kernel8.img: kernel
	aarch64-unknown-linux-gnu-objcopy -O binary kernel kernel8.img

kernel: $(OBJS)
	aarch64-unknown-linux-gnu-ld -nostdlib -T link.lds -o kernel $(OBJS)

%.o: %.s
	aarch64-unknown-linux-gnu-gcc -c $< -o $@
