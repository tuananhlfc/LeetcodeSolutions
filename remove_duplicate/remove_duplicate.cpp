/*
Problem 26. Remove Duplicates from Sorted Array (Easy)
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        // nums.erase(nums.begin() + i);
        return i + 1;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto it = nums.begin() + 1;
        while (it != nums.end()) {
            if (*it == *(it - 1)) nums.erase(it - 1);
            else it++;
        }
        return nums.size();
    }
};

int main() {
    vector<int> input {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    sol.removeDuplicates(input);
}
