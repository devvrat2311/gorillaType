# compiler 
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -D_POSIX_C_SOURCE=199309L

# Directories
SRC_DIR = src
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

# Executable
EXEC = $(BIN_DIR)/run_gorillaType

# Main file
MAIN = $(SRC_DIR)/main.c

# default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile source files to object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(BIN_DIR)/*.o $(EXEC)

# Phony targets
.PHONY: all clean
