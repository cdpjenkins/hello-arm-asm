all: kernel8.img

clean:
	rm -f *.o kernel kernel8.img

kernel8.img: kernel
	aarch64-unknown-linux-gnu-objcopy -O binary kernel kernel8.img

kernel: boot.o main.o
	aarch64-unknown-linux-gnu-ld -nostdlib -T link.lds -o kernel boot.o main.o

%.o: %.s
	aarch64-unknown-linux-gnu-gcc -c $< -o $@

# aarch64-linux-gnu-gcc -c boot.s -o boot.o
# aarch64-linux-gnu-gcc -c main.s -o main.o
# aarch64-linux-gnu-ld -nostdlib -T link.lds -o kernel boot.o main.o
# aarch64-linux-gnu-objcopy -O binary kernel kernel8.img
