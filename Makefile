CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T linker.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T linker.ld -Wl,-Map=final.map
OBJDUMP=arm-none-eabi-objcopy

all:main.o startup.o final.elf final.bin


main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^


startup.o:startup.c
	$(CC) $(CFLAGS) -o $@ $^
	
final.elf: main.o startup.o
	$(CC) *.o -T linker.ld -nostdlib -o final.elf
	
	
final.bin:final.elf
	$(OBJDUMP)	-O binary final.elf final.bin
	
clean:
	rm -rf *.o *.elf
