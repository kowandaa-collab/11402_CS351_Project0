#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> TwoSumArray(const std::vector<int>& nums, int target);
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target);

static void fail(const std::string& testName, const std::string& msg) {
    std::cerr << "[FAIL] " << testName << ": " << msg << "\n";
}

static bool isAscending(const std::vector<int>& idx) {
    return idx.size() != 2 || idx[0] <= idx[1];
}

// Accepts ANY valid pair (or empty when none exists).
// Also enforces "ascending order" requirement when size==2.
static bool checkAnyValidPair(const std::vector<int>& nums,
                              int target,
                              const std::vector<int>& ans,
                              bool solutionMustExist,
                              const std::string& testName) {
    if (ans.empty()) {
        if (solutionMustExist) {
            fail(testName, "expected a solution but got []");
            return false;
        }
        return true;
    }

    if (ans.size() != 2) {
        fail(testName, "answer must be size 0 or 2, got size=" + std::to_string(ans.size()));
        return false;
    }

    if (!isAscending(ans)) {
        fail(testName, "indices must be in ascending order");
        return false;
    }

    const int i = ans[0];
    const int j = ans[1];
    if (i == j) {
        fail(testName, "indices must be distinct");
        return false;
    }
    if (i < 0 || j < 0 || i >= static_cast<int>(nums.size()) || j >= static_cast<int>(nums.size())) {
        fail(testName, "indices out of range");
        return false;
    }

    const long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]);
    if (sum != target) {
        fail(testName, "nums[i] + nums[j] != target");
        return false;
    }

    return true;
}

static bool hasAnySolution(const std::vector<int>& nums, int target) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(nums.size()); ++j) {
            const long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]);
            if (sum == target) return true;
        }
    }
    return false;
}

static int runOne(const std::string& testName,
                  const std::vector<int>& nums,
                  int target,
                  bool solutionMustExist) {
    int failures = 0;

    const bool anySolution = hasAnySolution(nums, target);
    if (solutionMustExist && !anySolution) {
        fail(testName, "test is marked solutionMustExist but input has no solution");
        return 1;
    }
    if (!solutionMustExist && anySolution) {
        // It's still allowed, but makes the expectation ambiguous; keep tests clean.
        fail(testName, "test is marked 'no solution' but input DOES have a solution");
        return 1;
    }

    const auto ansA = TwoSumArray(nums, target);
    const auto ansH = TwoSumHashTable(nums, target);

    if (!checkAnyValidPair(nums, target, ansA, solutionMustExist, testName + " / TwoSumArray")) failures++;
    if (!checkAnyValidPair(nums, target, ansH, solutionMustExist, testName + " / TwoSumHashTable")) failures++;

    return failures == 0 ? 0 : 1;
}

int main() {
    int failures = 0;

    failures += runOne("simple case", {2, 7, 11, 15}, 9, true);
    failures += runOne("edge case (negatives)", {-1, -2, -3, 5, 10}, 8, true);
    failures += runOne("edge case (duplicates)", {3, 3}, 6, true);
    failures += runOne("single amount", {5}, 10, false);
    failures += runOne("no solution", {1, 2, 3}, 100, false);

    std::vector<int> big(10'000, 1);
    big[123] = 100;
    big[9876] = 200;
    failures += runOne("stress case", big, 300, true);

    if (failures == 0) {
        std::cout << "ALL TESTS PASSED\n";
        return 0;
    }
    std::cout << "SOME TESTS FAILED\n";
    return 1;
}

