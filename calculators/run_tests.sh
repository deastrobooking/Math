#!/bin/bash
# Test runner for all calculator implementations

echo "=========================================="
echo "Mathematics Calculator Test Suite"
echo "=========================================="
echo ""

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Track results
PASSED=0
FAILED=0

# Function to run and check a command
run_test() {
    local name=$1
    local command=$2
    
    echo -e "${YELLOW}Testing: $name${NC}"
    
    if eval "$command" > /dev/null 2>&1; then
        echo -e "${GREEN}✓ PASS${NC}"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAIL${NC}"
        ((FAILED++))
    fi
    echo ""
}

# Python Tests
echo "=== Python Calculators ==="
if command -v python3 &> /dev/null; then
    cd python
    run_test "Python Calculus Calculator" "python3 calculus_calculator.py"
    run_test "Python Algebra Calculator" "python3 algebra_calculator.py"
    run_test "Python Statistics Calculator" "python3 statistics_calculator.py"
    cd ..
else
    echo -e "${RED}Python3 not found, skipping Python tests${NC}"
    echo ""
fi

# Rust Tests
echo "=== Rust Calculators ==="
if command -v cargo &> /dev/null; then
    cd rust
    run_test "Rust Calculus Calculator" "cargo run --quiet --bin calculus_calculator"
    run_test "Rust Algebra Calculator" "cargo run --quiet --bin algebra_calculator"
    run_test "Rust Statistics Calculator" "cargo run --quiet --bin statistics_calculator"
    cd ..
else
    echo -e "${RED}Cargo not found, skipping Rust tests${NC}"
    echo ""
fi

# C++ Tests
echo "=== C++ Calculators ==="
if command -v g++ &> /dev/null; then
    cd cpp
    
    # Compile and run calculus
    if g++ -std=c++17 -O2 calculus_calculator.cpp -o calculus_calc 2>/dev/null; then
        run_test "C++ Calculus Calculator" "./calculus_calc"
        rm -f calculus_calc
    else
        echo -e "${RED}Failed to compile C++ Calculus Calculator${NC}"
        ((FAILED++))
    fi
    
    # Compile and run algebra
    if g++ -std=c++17 -O2 algebra_calculator.cpp -o algebra_calc 2>/dev/null; then
        run_test "C++ Algebra Calculator" "./algebra_calc"
        rm -f algebra_calc
    else
        echo -e "${RED}Failed to compile C++ Algebra Calculator${NC}"
        ((FAILED++))
    fi
    
    cd ..
else
    echo -e "${RED}g++ not found, skipping C++ tests${NC}"
    echo ""
fi

# C Tests
echo "=== C Calculators ==="
if command -v gcc &> /dev/null; then
    cd c
    
    # Compile and run calculus
    if gcc -std=c99 -O2 -lm calculus_calculator.c -o calculus_calc 2>/dev/null; then
        run_test "C Calculus Calculator" "./calculus_calc"
        rm -f calculus_calc
    else
        echo -e "${RED}Failed to compile C Calculus Calculator${NC}"
        ((FAILED++))
    fi
    
    # Compile and run algebra
    if gcc -std=c99 -O2 -lm algebra_calculator.c -o algebra_calc 2>/dev/null; then
        run_test "C Algebra Calculator" "./algebra_calc"
        rm -f algebra_calc
    else
        echo -e "${RED}Failed to compile C Algebra Calculator${NC}"
        ((FAILED++))
    fi
    
    cd ..
else
    echo -e "${RED}gcc not found, skipping C tests${NC}"
    echo ""
fi

# Summary
echo "=========================================="
echo "Test Summary"
echo "=========================================="
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"
echo ""

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed! ✗${NC}"
    exit 1
fi
