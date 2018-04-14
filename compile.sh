nasm -f elf32 kernel.asm -o kasm.o
g++ -m32 -c kernel.cpp -o kc.o
ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o
cp kernel.bin ./Pluto/boot/kernel.bin
qemu-system-i386 -kernel kernel.bin
