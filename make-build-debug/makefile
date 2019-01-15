# sudo apt-get install g++ binutils libc6-dev-i386
# sudo apt-get install qemu qemu-system-i386 grub-legacy xorriso

#GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -Wall -pedantic -Wextra -g
GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -g
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = obj/kernel.o \
          obj/loader.o \
          obj/gdt.o \
          obj/memorymanagement.o \
          obj/multitasking.o \
          obj/hardwarecommunication/interruptstubs.o \
          obj/syscalls.o \
          obj/net/arp.o \
          obj/net/ipv4.o \
          obj/net/icmp.o \
          obj/net/udp.o \
          obj/net/tcp.o \
          obj/net/etherframe.o \
          obj/hardwarecommunication/interrupts.o \
          obj/hardwarecommunication/pci.o \
          obj/hardwarecommunication/port.o \
          obj/drivers/hw/amd_am79c973.o \
          obj/drivers/hw/keyboard.o \
          obj/drivers/hw/ata.o \
          obj/drivers/hw/vga.o \
          obj/drivers/hw/driver.o \
          obj/drivers/hw/mouse.o

run: pluto.iso
	 qemu-system-i386 -kernel kernel.bin

obj/%.o: ../core/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: ../src/drivers/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: ../src/gui/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: ../src/drivers/hw/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: ../src/hardwarecommunication/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: ../src/hardwarecommunication/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

obj/%.o: ../src/drivers/net/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

ob/%.o: ../src/%.cpp
	mkdir -p $(@Đ)
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: ../src/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

obj/%.o: ../src/drivers/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

kernel.bin: ../linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

pluto.iso: kernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp kernel.bin iso/boot/
	echo 'set timeout=0'                      > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "Pluto OS v. 0.1" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin'    >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=pluto.iso

install: kernel.bin
	sudo cp $< /boot/kernel.bin

.PHONY: clean
clean:
	rm -rf obj kernel.bin pluto.iso iso
