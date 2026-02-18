# Axiomkernel
A minimal educational operating system kernel built from scratch.

## Purpose
This project is built to understand low-level system architecture including boot process, memory management, and interrupt handling.

## Development Environment
- Windows 11
- WSL (Ubuntu)
- GCC
- NASM
- QEMU

---

## progress log 

### Day 1
- Set up WSL (Ubuntu)
- Installed GCC, NASM, GRUB tools, QEMU 
- Configured SSH authentication with Github
- Initialized project structure

### Day 2 
- Created inital kernel entry file (kernel_main)
- Established basic kernel structure

### Day 3
- Created custom linker script
- Defined kernel load address at 1MB
- Structured memory sections (.text, .data, .bss)

### Day 4
- Created boot assembly file (`boot.asm`)
- Defined `_start` as kernel entry point
- Connected assembly entry to `kernel_main` in C
- Established basic kernel execution flow

### Day 5
- Compiled assembly and C in freestanding mode
- Linked object files using custom linker script
- Generated `kernel.bin` binary

### Day 6
- Created GRUB configuration
- Generated bootable ISO image
- Successfully booted AxiomKernal in QEMU

## First Boot

AxiomKernal successfully booting and printing output via VGA memory-mapped I/O.
<img width="720" height="137" alt="first_boot" src="https://github.com/user-attachments/assets/94ceb8b2-cea7-4d47-8ade-95b8d03d3d95" />
