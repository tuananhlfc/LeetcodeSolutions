#include <iostream>
#include <vector>
#include "Fibonacci.hpp"

struct TestCase {
    int input_;
    uint64_t expected_;
    TestCase(const int input, const uint64_t expected) : input_(input), expected_(expected) {}
};

int main() {
    std::vector<TestCase> testCases;
    testCases.emplace_back(3, 2);
    testCases.emplace_back(1, 2);
    testCases.emplace_back(0, 0);
    testCases.emplace_back(27, 196'418);
    testCases.emplace_back(36, 14'930'352);

    // start testing
    Solution sol;
    for (const auto& test: testCases) {
        const auto yourResult = sol.fibonacci(test.input_);
        if (yourResult != test.expected_) {
            std::cout << "Test fail, expected " << test.expected_ << " but got " << yourResult << std::endl;
            return 1;
        }
    }

    // All tests passed
    std::cout << "All tests passed. Congratulation!\n";
    return 0;
}

