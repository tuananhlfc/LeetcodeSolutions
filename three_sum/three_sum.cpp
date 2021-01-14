/*
Problem 167. Two Sum II - Input array is sorted (Easy)
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        if (nums.size() < 3) return ans;        
        sort(nums.begin(), nums.end());
        
        for (auto pivot = nums.begin(); pivot < nums.end() - 2; ++pivot) {
            auto lo = pivot + 1, hi = prev(nums.end());
            const auto target = -(*pivot);
            while (lo < hi) {
                const auto sum = *lo + *hi;
                if (sum < target) {
                    ++lo;
                } else if (sum > target) {
                    --hi;
                } else {
                    vector<int> triple {*pivot, *lo, *hi};
                    ans.emplace_back(triple);
                    lo++;
                    hi--;
                    while (*lo == *(lo - 1) && lo < hi) ++lo;
                    if (lo >= hi) break;
                    while (*hi == *(hi + 1)) --hi;
                }
            }
            
            while (*pivot == *(pivot + 1) && (pivot < nums.end() - 2))
                ++pivot;
            if (*pivot > 0) break;
        }

        return ans;
    }
};

class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> answer_set;

        if (nums.size() < 3) return ans;        
        sort(nums.begin(), nums.end());

        for (auto pivot = nums.begin() + 1; pivot < nums.end() - 1; ++pivot) {
            auto loIt = nums.begin(), hiIt = prev(nums.end());
            while (loIt != pivot && hiIt != pivot) {
                auto sum = *loIt + *hiIt, target = -(*pivot);
                if (sum < target) {
                    ++loIt;
                } else if (sum > target) {
                    --hiIt;
                } else {
                    vector<int> triplet {*loIt, *pivot, *hiIt};
                    // if (find(ans.begin(), ans.end(), triplet) == ans.end())
                    //     ans.push_back(triplet);
                    answer_set.emplace(triplet);
                    ++loIt;
                    --hiIt;
                }
            }
        }
        ans.assign(answer_set.begin(), answer_set.end());
        return ans;
    }
};

int main() {
    vector<int> input {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    sol.threeSum(input);
}
