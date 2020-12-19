/*
Problem 167. Two Sum II - Input array is sorted (Easy)
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        auto left_it = numbers.begin(), right_it = prev(numbers.end());
        while (left_it != right_it) {
            auto sum = *left_it + *right_it;
            if (sum < target) {
                left_it++;
            } else if (sum > target) {
                right_it--;
            } else {
                ans[0] = distance(numbers.begin(), left_it) + 1;
                ans[1] = distance(numbers.begin(), right_it) + 1;
                break;
            }
        }
        return ans;
    }
};
