CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRC_DIR = src
BUILD_DIR = build

# Find all .cpp files recursively under src
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Object files go into build/, mirroring src structure
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable goes to the root folder (next to Makefile)
TARGET = ChiBebinam.out

all: $(TARGET)

# Link object files into executable in root directory
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into corresponding object file under build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove build folder and executable
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
