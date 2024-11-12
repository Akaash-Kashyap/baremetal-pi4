CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align
GCCPATH = gcc-arm-10.3-2021.07-mingw-w64-i686-aarch64-none-elf/bin

all: clean kernel8.img

boot.o: boot.S
	echo "Building boot.S"
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c boot.S -o boot.o
	echo "Built boot.S"


%.o: %.c
	echo "Building $<"
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@
	echo "Built $@"

kernel8.img: boot.o $(OFILES)
	echo "Building kernel8.img"
	$(GCCPATH)/aarch64-none-elf-ld -nostdlib boot.o $(OFILES) -T link.ld -o kernel8.elf
	$(GCCPATH)/aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img
	echo "Built kernel8.img"

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true
	echo "Cleaned up"