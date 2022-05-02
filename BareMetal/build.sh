aarch64-linux-gnu-gcc -c boot.s -o boot.o
aarch64-linux-gnu-gcc -c main.s -o main.o
aarch64-linux-gnu-ld -nostdlib -T link.lds -o kernel boot.o main.o
aarch64-linux-gnu-objcopy -O binary kernel kernel8.img
