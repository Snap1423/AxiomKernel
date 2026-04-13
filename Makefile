.PHONY: build run clean

build:
	mkdir -p build
	nasm -f elf32 src/arch/boot.asm -o build/boot.o
	gcc -m32 -ffreestanding -c src/kernel/kernel.c -o build/kernel.o
	gcc -m32 -ffreestanding -c src/kernel/memory.c -o build/memory.o
	gcc -m32 -ffreestanding -c src/drivers/vga.c -o build/vga.o
	gcc -m32 -ffreestanding -c src/drivers/keyboard.c -o build/keyboard.o
	ld -m elf_i386 -T linker.ld build/boot.o build/kernel.o build/memory.o build/vga.o build/keyboard.o -o build/kernel.elf
	cp build/kernel.elf iso/boot/kernel.bin
	grub-mkrescue -o build/AxiomKernal.iso iso

run:
	qemu-system-i386 -boot d -cdrom build/AxiomKernal.iso

clean:
	rm -rf build
