CFLAGS = -Wall -Iinclude

SRC_DIR = src
EXAMPLE_DIR = examples
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

EXAMPLE_DIRS = $(dir $(shell find ./examples/ -mindepth 2 -type f -name 'Makefile'))

.PHONY: all clean docs $(EXAMPLE_DIRS)

all: $(OBJS) $(TARGETS) $(EXAMPLE_DIRS)

$(EXAMPLE_DIRS):
	$(MAKE) -C $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

docs: 
	doxygen ds.bak

clean:
	rm -rf $(BUILD_DIR) $(TARGET)


