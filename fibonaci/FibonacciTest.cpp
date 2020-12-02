#include <iostream>
#include <vector>
#include <chrono>
#include "Fibonacci.hpp"

struct TestCase {
    int input_;
    uint64_t expected_;
    TestCase(const int input, const uint64_t expected) : input_(input), expected_(expected) {}
};

int main() {
    std::vector<TestCase> testCases;
    testCases.emplace_back(3, 2);
    testCases.emplace_back(1, 1);
    testCases.emplace_back(0, 0);
    testCases.emplace_back(27, 196'418);
    testCases.emplace_back(49, 7'778'742'049);

    // start testing
    Solution sol;
    for (const auto& test: testCases) {
        auto start_time = std::chrono::system_clock::now();
        const auto yourResult = sol.fibonacci2(test.input_);
        auto end_time = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        if (yourResult != test.expected_) {
            std::cout << "Test fail, expected " << test.expected_ << " but got " << yourResult << std::endl;
            return 1;
        }
        std::cout << "Test passed, (input, output) = (" << test.input_ << " , " << yourResult << ")\n";
        std::cout << "Test cost " << duration << " nanoseconds\n";
    }

    // All tests passed
    std::cout << "All tests passed. Congratulation!\n";
    return 0;
}

