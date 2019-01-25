# sudo apt-get install g++ binutils libc6-dev-i386
# sudo apt-get install qemu qemu-system-i386 grub-legacy xorriso

#GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -Wall -pedantic -Wextra -g
GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -g
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = build/kernel.o \
          build/loader.o \
          build/gdt.o \
          build/memorymanagement.o \
          build/multitasking.o \
          build/hardwarecommunication/interruptstubs.o \
          build/syscalls.o \
          build/net/arp.o \
          build/net/ipv4.o \
          build/net/icmp.o \
          build/net/udp.o \
          build/net/tcp.o \
          build/net/etherframe.o \
          build/hardwarecommunication/InterruptManager.o \
          build/hardwarecommunication/interrupts.o \
          build/hardwarecommunication/pci.o \
          build/hardwarecommunication/port.o \
          build/drivers/hw/amd_am79c973.o \
          build/drivers/hw/keyboard.o \
          build/drivers/hw/ata.o \
          build/drivers/hw/vga.o \
          build/drivers/hw/driver.o \
          build/drivers/hw/mouse.o \
          build/gui/CompositeWidget.o \
          build/gui/desktop.o \
          build/gui/widget.o \
          build/gui/Window.o \
          build/gui/window.o

run: build/kernel.bin
	 qemu-system-i386 -kernel build/kernel.bin

build/%.o: core/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

build/%.o: src/drivers/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

build/%.o: src/gui/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

build/%.o: src/drivers/hw/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

build/%.o: src/hardwarecommunication/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

build/%.o: src/hardwarecommunication/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

build/%.o: src/drivers/net/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

build/%.o: src/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

build/%.o: src/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

build/%.o: src/drivers/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

build/kernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

build/pluto.iso: build/kernel.bin
	mkdir -p build/iso/boot/grub
	cp build/kernel.bin build/iso/boot/
	echo 'set timeout=0'                      > build/iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> build/iso/boot/grub/grub.cfg
	echo ''                                  >> build/iso/boot/grub/grub.cfg
	echo 'menuentry "Pluto OS v. 0.1" {' >> build/iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin'    >> build/iso/boot/grub/grub.cfg
	echo '  boot'                            >> build/iso/boot/grub/grub.cfg
	echo '}'                                 >> build/iso/boot/grub/grub.cfg
	grub-mkrescue --output=build/pluto.iso

install: build/kernel.bin
	sudo cp $< /boot/kernel.bin

.PHONY: clean
clean:
	rm -rf build
