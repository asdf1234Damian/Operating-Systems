#!/usr/bin/env bash
nasm src/bootloader.asm -f bin -o bin/bootloader
dd if=/dev/zero of=images/escomOS.flp bs=1024 count=1440
dd if=bin/bootloader of=images/escomOS.flp seek=0 count=1 conv=notrunc
genisoimage -quiet -V 'escomOS' -input-charset iso8859-1 -o ./images/escomOS.iso -b images/escomOS.flp -hide images/escomOS.flp .
qemu-system-i386 -fda images/escomOS.flp
qemu-system-i386 -cdrom images/escomOS.iso

nasm src/bootloaderVidMem.asm -f bin -o bin/bootloadervidMem
dd if=/dev/zero of=images/escomOSVidMem.flp bs=1024 count=1440
dd if=bin/bootloaderVidMem of=images/escomOSVidMem.flp seek=0 count=1 conv=notrunc
genisoimage -quiet -V 'escomOSVidMem' -input-charset iso8859-1 -o ./images/escomOSVidMem.iso -b images/escomOSVidMem.flp -hide images/escomOSVidMem.flp .
qemu-system-i386 -fda images/escomOSVidMem.flp
qemu-system-i386 -cdrom images/escomOSVidMem.iso
