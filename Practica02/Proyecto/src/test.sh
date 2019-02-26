#!/usr/bin/env bash
nasm bootloader.asm -f bin
dd if=/dev/zero of=escomos.flp bs=1024 count=1440
dd if=bootloader of=escomos.flp seek=0 count=1 conv=notrunc
qemu-system-i386 -fda escomos.flp 
