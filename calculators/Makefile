# Makefile for C and C++ Calculators

# Compiler settings
CC = gcc
CXX = g++
CFLAGS = -std=c99 -O2 -Wall -Wextra
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
LDFLAGS = -lm

# Directories
C_DIR = c
CPP_DIR = cpp
BUILD_DIR = build

# C programs
C_SOURCES = $(wildcard $(C_DIR)/*.c)
C_TARGETS = $(patsubst $(C_DIR)/%.c,$(BUILD_DIR)/%_c,$(C_SOURCES))

# C++ programs
CPP_SOURCES = $(wildcard $(CPP_DIR)/*.cpp)
CPP_TARGETS = $(patsubst $(CPP_DIR)/%.cpp,$(BUILD_DIR)/%_cpp,$(CPP_SOURCES))

# All targets
ALL_TARGETS = $(C_TARGETS) $(CPP_TARGETS)

.PHONY: all clean c cpp test help

# Default target
all: $(BUILD_DIR) $(ALL_TARGETS)
	@echo "✓ All calculators compiled successfully!"
	@echo "Executables in $(BUILD_DIR)/"

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Compile C programs
$(BUILD_DIR)/%_c: $(C_DIR)/%.c | $(BUILD_DIR)
	@echo "Compiling C: $<"
	@$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

# Compile C++ programs
$(BUILD_DIR)/%_cpp: $(CPP_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compiling C++: $<"
	@$(CXX) $(CXXFLAGS) $< -o $@

# Compile only C programs
c: $(BUILD_DIR) $(C_TARGETS)
	@echo "✓ C calculators compiled!"

# Compile only C++ programs
cpp: $(BUILD_DIR) $(CPP_TARGETS)
	@echo "✓ C++ calculators compiled!"

# Run all C tests
test-c: c
	@echo "\n=== Testing C Calculators ==="
	@for target in $(C_TARGETS); do \
		echo "\n--- Running $$target ---"; \
		./$$target; \
	done

# Run all C++ tests
test-cpp: cpp
	@echo "\n=== Testing C++ Calculators ==="
	@for target in $(CPP_TARGETS); do \
		echo "\n--- Running $$target ---"; \
		./$$target; \
	done

# Run all tests
test: all
	@$(MAKE) test-c
	@$(MAKE) test-cpp

# Clean build artifacts
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)
	@echo "✓ Clean complete!"

# Show help
help:
	@echo "Mathematics Calculator Makefile"
	@echo ""
	@echo "Usage:"
	@echo "  make          - Compile all C and C++ calculators"
	@echo "  make c        - Compile only C calculators"
	@echo "  make cpp      - Compile only C++ calculators"
	@echo "  make test     - Compile and run all calculators"
	@echo "  make test-c   - Compile and run C calculators"
	@echo "  make test-cpp - Compile and run C++ calculators"
	@echo "  make clean    - Remove all compiled binaries"
	@echo "  make help     - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make && ./build/calculus_calculator_c"
	@echo "  make cpp && ./build/algebra_calculator_cpp"

# Individual calculator targets (for convenience)
.PHONY: calculus algebra statistics

calculus: $(BUILD_DIR)/calculus_calculator_c $(BUILD_DIR)/calculus_calculator_cpp
	@echo "✓ Calculus calculators ready!"

algebra: $(BUILD_DIR)/algebra_calculator_c $(BUILD_DIR)/algebra_calculator_cpp
	@echo "✓ Algebra calculators ready!"
