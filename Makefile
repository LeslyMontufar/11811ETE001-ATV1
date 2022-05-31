CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m3 -mthumb -Wall -O0 # Cortex M3 para o STM32F103

all: startup.o main.o

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o