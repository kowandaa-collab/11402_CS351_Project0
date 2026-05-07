#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<int> TwoSumArray(const std::vector<int>& nums, int target) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(nums.size()); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j}; // i < j by construction
            }
        }
    }
    return {};
}

std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen; // value -> index
    seen.reserve(nums.size());

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        const int need = target - nums[i];
        const auto it = seen.find(need);
        if (it != seen.end()) {
            int a = it->second;
            int b = i;
            if (a > b) std::swap(a, b);
            return {a, b};
        }

        // Insert AFTER lookup so we never reuse the same element twice
        if (seen.find(nums[i]) == seen.end()) {
            seen.emplace(nums[i], i);
        }
    }

    return {};
}

// Required signature from README.md
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    return TwoSumHashTable(nums, target);
}
