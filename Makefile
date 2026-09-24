CC = gcc
FLAGS = -Wall -Wextra -pedantic -std=c99
LDFLAGS = -I./include/ -lncurses -lm

TARGET = skyrimRL

SRCS = ./src/*.c

# 4. Default Target (The one run by default when you just type 'make')
all: $(TARGET) run

# 5. Rule to Link the Executable
$(TARGET):
	$(CC) $(SRCS) $(CFLAGS) -o $@ $(LDFLAGS)

run:
	./$(TARGET)

clean:
	rm $(TARGET)
