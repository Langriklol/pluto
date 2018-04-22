#!/usr/bin/env bash
nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o -O2
echo "compilled"
ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o
echo "linked"
cp kernel.bin ./Pluto/boot/kernel.bin
#grub-mkrescue -o Pluto.iso Pluto/
qemu-system-i386 -kernel kernel.bin

read a