CFLAGS = -Wall -Iinclude

EXAMPLE_DIR = examples
BUILD_DIR = build
TEST_DIR = tests

EXAMPLE_DIRS = $(dir $(shell find ./examples/ -mindepth 2 -type f -name 'Makefile'))

TESTS = $(wildcard $(TEST_DIR)/*.c)
TESTS_EX = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.bin, $(TESTS))

.PHONY: all clean docs $(EXAMPLE_DIRS)

all: $(TESTS_EX)

$(BUILD_DIR)/%.bin: $(TEST_DIR)/%.c src/tests.c include/testing/tests.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $< src/tests.c -Iinclude
 
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


