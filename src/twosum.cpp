#include <vector>
#include <unordered_map>

// Brute force approach: O(n^2) time, O(1) space
std::vector<int> TwoSumArray(const std::vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // No solution found (though problem assumes exactly one)
}

// Hash table approach: O(n) time, O(n) space
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map; // value -> index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {}; // No solution found (though problem assumes exactly one)
}
