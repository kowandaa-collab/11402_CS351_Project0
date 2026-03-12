#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Approach 1: Hash Map Solution
// Time Complexity: O(n), Space Complexity: O(n)
vector<int> twoSumHashMap(vector<int>& nums, int target) {
    unordered_map<int, int> map;  // value -> index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in map
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        
        // Store current number and its index
        map[nums[i]] = i;
    }
    
    // No valid answer found
    return {};
}

// Approach 2: Two Pointers Solution
// Note: Requires sorted array, returns original indices
// Time Complexity: O(n log n), Space Complexity: O(n) for sorted array
vector<int> twoSumTwoPointers(vector<int>& nums, int target) {
    // Create pairs of (value, original_index)
    vector<pair<int, int>> indexed;
    for (int i = 0; i < nums.size(); i++) {
        indexed.push_back({nums[i], i});
    }
    
    // Sort by value
    sort(indexed.begin(), indexed.end());
    
    int left = 0, right = indexed.size() - 1;
    
    while (left < right) {
        int sum = indexed[left].first + indexed[right].first;
        
        if (sum == target) {
            // Return original indices
            return {indexed[left].second, indexed[right].second};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // No valid answer found
    return {};
}
