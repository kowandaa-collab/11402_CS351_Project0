# Two Sum

Given an array of integers and a target sum, find the indices of the two distinct numbers that add up to the target. You may assume exactly one valid answer exists and you cannot reuse the same element twice; indices can be returned in any order.

## Requirements

### Language & Tools
- **Language**: C++20
- **Data Structure**: STL `vector`

### Implementations

#### 1. TwoSumArray
- Brute force approach using nested loops
- Time Complexity: O(n²)
- Space Complexity: O(1)
- Iterate through each element and check all other elements for target sum

#### 2. TwoSumHashTable
- Hash table (unordered_map) approach
- Time Complexity: O(n)
- Space Complexity: O(n)
- Store elements in hash map for O(1) lookup while iterating

### Function Signature
```cpp
std::vector<int> twoSum(const std::vector<int>& nums, int target);
```

### Test Cases
- **Test 1**: `nums = [2, 7, 11, 15]`, `target = 9` → `[0, 1]`
- **Test 2**: `nums = [3, 2, 4]`, `target = 6` → `[1, 2]`
- **Test 3**: `nums = [3, 3]`, `target = 6` → `[0, 1]`
- **Test 4**: `nums = [1, 2, 3, 4, 5]`, `target = 9` → `[3, 4]`
- **Test 5**: `nums = [-1, -2, -3, 5, 10]`, `target = 7` → `[1, 4]` or `[3, 4]`


## CI/CD Pipeline

### GitHub Actions Workflow
Automated testing runs on every push and pull request to validate both implementations:
- Tests execute for `TwoSumArray()` (brute force)
- Tests execute for `TwoSumHashTable()` (hash table approach)
- All test cases must pass before merge

**Workflow File**: `.github/workflows/ci-cd.yml`

### Dockerfile
Containerized deployment with automated testing:
- Base image: C++20 compatible environment
- Build source code and compile both implementations
- Execute unit tests during Docker build
- Ready for production deployment

**Dockerfile Location**: `./Dockerfile`

### Build & Test Commands
```bash
# Local build with Docker
docker build -t two-sum:latest .

# Run tests inside container
docker run two-sum:latest /app/build/tests
```

### Pipeline Stages
1. **Checkout**: Pull source code
2. **Build**: Compile C++20 code with both implementations
3. **Test**: Run unit tests for all test cases
4. **Docker Build**: Create containerized image with tests
5. **Status Reports**: Pass/fail notifications

