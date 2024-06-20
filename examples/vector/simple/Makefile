TARGET = example_vector_simple
BUILD_DIR = ../../../build
INCLUDE_DIR = ../../../include

OBJS = $(wildcard $(BUILD_DIR)/*.o)

.PHONY: all

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): main.c $(OBJS)
	$(CC) -o $@ $^ -I $(INCLUDE_DIR) -std=c11