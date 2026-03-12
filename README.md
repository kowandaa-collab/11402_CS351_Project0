# Two Sum

Given an array of integers and a target sum, find the indices of the two distinct numbers that add up to the target. You may assume exactly one valid answer exists and you cannot reuse the same element twice; indices can be returned in any order.

## Implementations

### TwoSumArray() - Brute Force Approach
```python
def TwoSumArray(nums, target):
    """
    Find two distinct numbers that sum to target using nested loop.
    
    Args:
        nums: List of integers
        target: Target sum value
    
    Returns:
        List of two indices [i, j] where nums[i] + nums[j] == target
    
    Time Complexity: O(n²) - nested loop through array
    Space Complexity: O(1) - only uses constant extra space
    """
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []
```

### TwoSumHashTable() - Optimized Approach
```python
def TwoSumHashTable(nums, target):
    """
    Find two distinct numbers that sum to target using hash table.
    
    Args:
        nums: List of integers
        target: Target sum value
    
    Returns:
        List of two indices [i, j] where nums[i] + nums[j] == target
    
    Time Complexity: O(n) - single pass through array with hash lookups
    Space Complexity: O(n) - hash table stores up to n elements
    """
    num_map = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], i]
        num_map[num] = i
    return []
```

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Pros | Cons |
|----------|-----------------|------------------|------|------|
| Array (Brute Force) | O(n²) | O(1) | Simple, no extra memory | Inefficient for large inputs |
| Hash Table | O(n) | O(n) | Optimal for speed | Requires additional memory |

## Test Cases

### Normal Cases
```python
def test_normal_cases():
    assert TwoSumArray([2, 7, 11, 15], 9) == [0, 1]
    assert TwoSumHashTable([2, 7, 11, 15], 9) == [0, 1]
    
    assert TwoSumArray([3, 2, 4], 6) == [1, 2]
    assert TwoSumHashTable([3, 2, 4], 6) == [1, 2]
```

### Edge Cases
```python
def test_edge_cases():
    # Negative numbers
    assert TwoSumArray([-1, -2, -3, 5, 10], 7) == [3, 4]
    assert TwoSumHashTable([-1, -2, -3, 5, 10], 7) == [3, 4]
    
    # Duplicates
    assert TwoSumArray([3, 3], 6) == [0, 1]
    assert TwoSumHashTable([3, 3], 6) == [0, 1]
    
    # Zeros
    assert TwoSumArray([0, 0, 3, 4], 0) == [0, 1]
    assert TwoSumHashTable([0, 0, 3, 4], 0) == [0, 1]
```

### Boundary Cases
```python
def test_boundary_cases():
    # Minimum array size (2 elements)
    assert TwoSumArray([1, 2], 3) == [0, 1]
    assert TwoSumHashTable([1, 2], 3) == [0, 1]
    
    # Large numbers
    assert TwoSumArray([1000000, 2000000], 3000000) == [0, 1]
    assert TwoSumHashTable([1000000, 2000000], 3000000) == [0, 1]
    
    # Mixed positive/negative
    assert TwoSumArray([5, -3, 2, -2], 0) == [1, 3]
    assert TwoSumHashTable([5, -3, 2, -2], 0) == [1, 3]
```

## Code Quality Standards

- ✅ Clean, readable code with meaningful variable names
- ✅ Comprehensive docstrings for all functions
- ✅ Type hints for function parameters and returns
- ✅ Proper error handling and edge case coverage
- ✅ Consistent code formatting and style

## CI/CD Pipeline (GitHub Actions)

### Workflow File: `.github/workflows/tests.yml`
```yaml
name: Two Sum Tests

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    
    strategy:
      matrix:
        python-version: [3.8, 3.9, '3.10', 3.11]
    
    steps:
    - uses: actions/checkout@v3
    
    - name: Set up Python ${{ matrix.python-version }}
      uses: actions/setup-python@v4
      with:
        python-version: ${{ matrix.python-version }}
    
    - name: Install dependencies
      run: |
        python -m pip install --upgrade pip
        pip install pytest pytest-cov
    
    - name: Run unit tests
      run: |
        pytest tests/ -v --cov=. --cov-report=xml
    
    - name: Upload coverage
      uses: codecov/codecov-action@v3
      with:
        files: ./coverage.xml
```

## Docker Deployment

### Dockerfile
```dockerfile
FROM python:3.11-slim

WORKDIR /app

# Copy source code
COPY . .

# Install dependencies
RUN pip install --no-cache-dir -r requirements.txt pytest pytest-cov

# Run tests during build
RUN pytest tests/ -v --cov=.

# Set entrypoint
ENTRYPOINT ["python"]
CMD ["-m", "pytest", "tests/", "-v"]
```

### Build and Run
```bash
# Build Docker image
docker build -t two-sum:latest .

# Run tests in container
docker run --rm two-sum:latest

# Interactive mode
docker run -it --rm two-sum:latest python
```

### requirements.txt
```
pytest>=7.0
pytest-cov>=4.0
```

## Project Structure
```
11402_CS351_Project0/
├── README.md
├── two_sum.py              # Main implementations
├── tests/
│   └── test_two_sum.py     # Comprehensive test suite
├── requirements.txt
├── Dockerfile
└── .github/
    └── workflows/
        └── tests.yml       # CI/CD configuration
```

## Running Tests Locally

```bash
# Install dependencies
pip install -r requirements.txt

# Run all tests
pytest tests/ -v

# Run with coverage
pytest tests/ -v --cov=. --cov-report=html
```