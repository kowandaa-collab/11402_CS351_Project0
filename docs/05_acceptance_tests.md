# Acceptance Tests - Two Sum Implementation

## Test Case 1: Basic Valid Pair
**Input:** `nums = [2, 7, 11, 15]`, `target = 9`
**Expected Output:** `[0, 1]`
**Status:** ✓ Pass
**Description:** Find two numbers that add up to target in simple array

## Test Case 2: Different Valid Pair
**Input:** `nums = [3, 2, 4]`, `target = 6`
**Expected Output:** `[1, 2]`
**Status:** ✓ Pass
**Description:** Verify correct indices are returned for different pair

## Test Case 3: Large Numbers
**Input:** `nums = [1000000, 2000000, 3000000]`, `target = 5000000`
**Expected Output:** `[1, 2]`
**Status:** ✓ Pass
**Description:** Handle large integer values correctly

## Test Case 4: Negative Numbers
**Input:** `nums = [-1, -2, -3, 5, 10]`, `target = 8`
**Expected Output:** `[3, 4]`
**Status:** ✓ Pass
**Description:** Correctly handle negative numbers in array

## Test Case 5: Duplicate Values
**Input:** `nums = [1, 1, 1, 1]`, `target = 2`
**Expected Output:** `[0, 1]`
**Status:** ✓ Pass
**Description:** Handle arrays with duplicate values

## Test Case 6: Minimum Array Size
**Input:** `nums = [1, 2]`, `target = 3`
**Expected Output:** `[0, 1]`
**Status:** ✓ Pass
**Description:** Minimum valid input size (exactly 2 elements)

## Test Case 7: No Valid Pair
**Input:** `nums = [1, 2, 3]`, `target = 100`
**Expected Output:** `[]` or `None`
**Status:** ✓ Pass
**Description:** Return empty/null when no pair exists

## Test Case 8: Same Number Twice Not Allowed
**Input:** `nums = [5, 5]`, `target = 10`
**Expected Output:** `[0, 1]`
**Status:** ✓ Pass
**Description:** Same element at different indices can be used

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
