#include <iostream>
#include <string>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target);
std::vector<int> TwoSumArray(const std::vector<int>& nums, int target);
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target);

static std::string vecToString(const std::vector<int>& v) {
    std::string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += std::to_string(v[i]);
        if (i + 1 < v.size()) s += ", ";
    }
    s += "]";
    return s;
}

static int runOne(const std::string& name,
                  const std::vector<int>& nums,
                  int target,
                  const std::vector<int>& expected) {
    const auto gotBrute = TwoSumArray(nums, target);
    const auto gotHash = TwoSumHashTable(nums, target);
    const auto gotReq = twoSum(nums, target);

    const bool okBrute = (gotBrute == expected);
    const bool okHash = (gotHash == expected);
    const bool okReq = (gotReq == expected);

    std::cout << name << "\n";
    std::cout << "  nums=" << vecToString(nums) << " target=" << target << "\n";
    std::cout << "  expected=" << vecToString(expected) << "\n";
    std::cout << "  TwoSumArray      =" << vecToString(gotBrute) << (okBrute ? "  PASS" : "  FAIL") << "\n";
    std::cout << "  TwoSumHashTable  =" << vecToString(gotHash) << (okHash ? "  PASS" : "  FAIL") << "\n";
    std::cout << "  twoSum (required)=" << vecToString(gotReq) << (okReq ? "  PASS" : "  FAIL") << "\n\n";

    return (okBrute && okHash && okReq) ? 0 : 1;
}

int main() {
    // User input mode:
    // Format: n then n integers then target
    // Example:
    // 4
    // 2 7 11 15
    // 9
    int n = 0;
    if (std::cin >> n) {
        std::vector<int> nums;
        nums.reserve(n);
        for (int i = 0; i < n; ++i) {
            int x = 0;
            if (!(std::cin >> x)) {
                std::cerr << "Invalid input: expected " << n << " integers.\n";
                return 1;
            }
            nums.push_back(x);
        }

        int target = 0;
        if (!(std::cin >> target)) {
            std::cerr << "Invalid input: expected target integer.\n";
            return 1;
        }

        const auto ans = twoSum(nums, target);
        std::cout << vecToString(ans) << "\n";
        return 0;
    }

    // No input provided => run the ONLY test cases (per user request).
    int failures = 0;
    failures += runOne("simple case", {2, 7, 11, 15}, 9, {0, 1});
    failures += runOne("edge case", {-1, -2, -3, 5, 10}, 8, {1, 4});
    failures += runOne("single amount", {5}, 10, {});

    std::vector<int> big(10'000, 1);
    big[123] = 100;
    big[9876] = 200;
    failures += runOne("stress case", big, 300, {123, 9876});

    std::cout << (failures == 0 ? "ALL TESTS PASSED\n" : "SOME TESTS FAILED\n");
    return failures == 0 ? 0 : 1;
}
