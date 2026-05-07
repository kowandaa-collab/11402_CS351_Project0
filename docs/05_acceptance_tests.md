# Acceptance Tests - Two Sum Implementation

This project accepts **any valid pair of indices** (as long as the indices are distinct, in-range, and sum to the target).
Per the SRS, when a pair is returned, indices must be in **ascending order**.

## simple case
- **Input**: `nums = [2, 7, 11, 15]`, `target = 9`
- **Expected**: any valid pair, e.g. `[0, 1]`

## edge case
- **Input**: `nums = [-1, -2, -3, 5, 10]`, `target = 8`
- **Expected**: any valid pair, e.g. `[1, 4]` (because `-2 + 10 = 8`)

## single amount
- **Input**: `nums = [5]`, `target = 10`
- **Expected**: `[]` (no pair exists)

## stress case
- **Input**: `n = 10,000` (engineered so exactly one pair sums to the target)
- **Expected**: the engineered indices (in ascending order)

## Performance Requirements
- Time Complexity: O(n) using hash map approach
- Space Complexity: O(n) for hash map storage
- Maximum array size: 10,000 elements
- Execution time: < 100ms for typical inputs

## Acceptance Criteria
- [x] All test cases pass
- [x] Handles edge cases (duplicates, negatives, no solution)
- [x] Returns correct indices (not values)
- [x] Meets performance requirements
- [x] Code is well-documented
