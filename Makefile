CFLAGS = -Wall -Iinclude

SRC_DIR = src
EXAMPLE_DIR = examples
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

EXAMPLES = $(wildcard $(EXAMPLE_DIR)/*.c)
TARGETS = $(patsubst $(EXAMPLE_DIR)/%.c, $(BUILD_DIR)/%, $(EXAMPLES))

.PHONY: all clean

all: $(OBJS) $(TARGETS)

$(BUILD_DIR)/%: $(EXAMPLE_DIR)/%.c $(OBJS) | $(BUILD_DIR) 
	$(CC) $(CFLAGS) $< -o $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)


