TARGET = pizzaria

CC = gcc
CFLAGS = -Wall -g -Iinclude

SRC_DIR = src
INC_DIR = include

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/pizza.c $(SRC_DIR)/ingrediente.c
HEADERS = $(INC_DIR)/pizza.h $(INC_DIR)/ingrediente.h

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o pizzaria
