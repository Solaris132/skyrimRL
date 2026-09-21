CC := gcc
FLAGS := -Wall -Wextra -pedantic -std=c99
LDFLAGS := -lncurses

TARGET := skyrimRL

# 2. Define directories
OBJ_DIR  := build
SRC_DIR  := src

# 3. Find all source files and map them to the object directory
SRCS     := $(wildcard $(SRC_DIR)/*.c)
OBJS     := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# 4. Default Target (The one run by default when you just type 'make')
all: $(TARGET)

# 5. Rule to Link the Executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 7. Phony Targets (Commands that don't represent actual files)
.PHONY: all clean

# 8. Clean Target to Reset the Directory
clean:
	rm -f $(OBJS) $(TARGET)
