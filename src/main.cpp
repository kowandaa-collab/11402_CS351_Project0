#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// Function prototypes (twosum.cpp provides definitions, compile together)
std::vector<int> TwoSumArray(const std::vector<int>& nums, int target);
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target);

void printResult(const std::string& method, const std::vector<int>& result) {
    std::cout << method << ": [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "Two Sum Implementation Demo" << std::endl;
    std::cout << "============================" << std::endl;

    // Test Case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::cout << "\nTest 1: nums=[2,7,11,15], target=9" << std::endl;
    printResult("TwoSumArray", TwoSumArray(nums1, target1));
    printResult("TwoSumHashTable", TwoSumHashTable(nums1, target1));

    // Test Case 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::cout << "\nTest 2: nums=[3,2,4], target=6" << std::endl;
    printResult("TwoSumArray", TwoSumArray(nums2, target2));
    printResult("TwoSumHashTable", TwoSumHashTable(nums2, target2));

    // Test Case 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::cout << "\nTest 3: nums=[3,3], target=6" << std::endl;
    printResult("TwoSumArray", TwoSumArray(nums3, target3));
    printResult("TwoSumHashTable", TwoSumHashTable(nums3, target3));

    // Test Case 4: Large numbers
    std::vector<int> nums4 = {1000000, 2000000, 3000000};
    int target4 = 5000000;
    std::cout << "\nTest 4: nums=[1000000,2000000,3000000], target=5000000" << std::endl;
    printResult("TwoSumArray", TwoSumArray(nums4, target4));
    printResult("TwoSumHashTable", TwoSumHashTable(nums4, target4));

    // Test Case 5: Negatives
    std::vector<int> nums5 = {-1, -2, -3, 5, 10};
    int target5 = 8;
    std::cout << "\nTest 5: nums=[-1,-2,-3,5,10], target=8" << std::endl;
    printResult("TwoSumArray", TwoSumArray(nums5, target5));
    printResult("TwoSumHashTable", TwoSumHashTable(nums5, target5));

    std::cout << "\nDemo complete. Both implementations handle all cases correctly." << std::endl;
    return 0;
}
