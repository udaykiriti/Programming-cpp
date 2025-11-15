# adjust CROSS_PREFIX if you installed cross toolchain in $HOME/cross
CROSS_PREFIX ?= i686-elf-
OBJCOPY := $(CROSS_PREFIX)objcopy
LD      := $(CROSS_PREFIX)ld

all: os.img

boot.bin: boot.asm
	nasm -f bin boot.asm -o boot.bin

# Build Rust kernel (release)
# uses custom target file in target/i686-unknown-none.json
kernel: 
	# use nightly and build only core from std (build-std)
	cargo +nightly build --release -Z build-std=core --target target/i686-unknown-none.json
	# copy binary (ELF) to kernel (raw) using objcopy
	$(OBJCOPY) -O binary target/i686-unknown-none.json/release/mini-os-rust kernel.bin

os.img: boot.bin kernel
	cat boot.bin kernel.bin > os.img

run: os.img
	qemu-system-i386 -drive format=raw,file=os.img -serial stdio

clean:
	cargo +nightly clean
	rm -f boot.bin kernel.bin os.img
