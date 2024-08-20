# Define variables
cc = arm-none-eabi-gcc
cflags = -c -mcpu=$(ach) -std=gnu11 -mthumb
lflags = -T linker.ld -nostdlib -Wl,-Map=executable.map
ach = cortex-m4

# Compile object files
main.o: main.c
	$(cc) $(cflags) $^ -o $@

GPIO_Prog.o: GPIO_Prog.c
	$(cc) $(cflags) $^ -o $@

RCC_Prog.o: RCC_Prog.c
	$(cc) $(cflags) $^ -o $@

SysTick_Prog.o: SysTick_Prog.c
	$(cc) $(cflags) $^ -o $@

startup.o: startup.c
	$(cc) $(cflags) $^ -o $@

# Link object files into the final executable
executable.elf: main.o GPIO_Prog.o RCC_Prog.o SysTick_Prog.o startup.o
	$(cc) $(lflags) $^ -o $@

# Build everything
all: executable.elf

# Clean up
clean:
	rm -rf *.o executable.elf



