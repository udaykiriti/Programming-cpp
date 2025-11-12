all:
	nasm -f bin boot.asm -o boot.bin
	i686-elf-gcc -ffreestanding -c kernel.c -o kernel.o
	i686-elf-ld -T linker.ld -o kernel.bin kernel.o
	cat boot.bin kernel.bin > os.img

run:
	qemu-system-x86_64 -drive format=raw,file=os.img