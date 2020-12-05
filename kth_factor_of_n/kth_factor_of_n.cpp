/* The kth Factor of n

Given two positive integers n and k.
A factor of an integer n is defined as an integer i where n % i == 0.
Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3554/
*/
#include <vector>
#include <cmath>

class Solution {
public:
    int kthFactor(int n, int k) {
        std::vector<int> factors1 {1}, factors2 {n};
        const int sqrt_n = sqrt(n);
        for (size_t i = 2; i <= sqrt_n; ++i) {
            if (n % i == 0) {
                factors1.push_back(i);
                factors2.push_back(n / i);
            }
            if (k == factors1.size()) return factors1.back();
        }
        if (sqrt_n * sqrt_n == n) factors2.pop_back();
        if (k <= factors1.size() + factors2.size()) {
            return (k <= factors1.size()) ? factors1[k - 1] : factors2[factors2.size() - k + factors1.size()]; 
        }
        return -1;
    }
};

// (1) use a double list, loop from sqrt(n) to 1
