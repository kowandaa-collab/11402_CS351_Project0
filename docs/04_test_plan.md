# Test Plan for Two Sum Implementation

## Overview
This document describes how we test the Two Sum implementations:

- `TwoSumArray(nums, target)` (brute force)
- `TwoSumHashTable(nums, target)` (hash table)

## Test Objectives
- Verify correctness (indices sum to target, distinct indices)
- Validate edge cases (duplicates, negatives, no solution)
- Ensure outputs follow the SRS rule: **indices in ascending order**
- Confirm the hash-table solution performs well for \(n=10{,}000\)

## Correctness Requirements (Pass Conditions)
For an input `(nums, target)`:

- If a solution exists, the function returns a vector of **two indices** `[i, j]` such that:
  - `0 <= i < nums.size()` and `0 <= j < nums.size()`
  - `i != j`
  - `nums[i] + nums[j] == target`
  - `i < j` (ascending order)
- If no solution exists (or input is too small), the function returns `[]` (empty vector).

## Test Approach
We use a small self-contained C++ test runner in `tests/tests.cpp` (no external frameworks):

- Each test calls **both implementations**.
- For tests where any valid answer is acceptable, we validate the returned indices by checking the sum and bounds (not by matching one exact pair).
- The program exits with:
  - `0` if all tests pass
  - `1` if any test fails (CI will mark the workflow as failed)

### Basic Functionality Tests

The core “categories” we keep are:

- **simple case**
- **edge case**
- **single amount**
- **stress case**

These map to concrete test vectors inside `tests/tests.cpp`.

## Acceptance Criteria
- `tests/tests.cpp` reports **ALL TESTS PASSED**
- GitHub Actions workflow completes successfully on push/PR

## Test Environment
- Language: C++20
- Platform: Local Windows (MSYS2/MinGW-w64) and CI on Ubuntu
- Test runner: `tests/tests.cpp` (no external dependency)

## Notes
- To run tests locally:

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -o tests_run src/twosum.cpp tests/tests.cpp
./tests_run
```

