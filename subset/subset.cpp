#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return {{}};

        auto n = nums.back();
        nums.pop_back();
        auto prev = subsets(nums);
        const auto prevSize = prev.size();

        for (int i = 0; i < prevSize; ++i) {
            vector<int> newSet (prev[i].begin(), prev[i].end());
            newSet.push_back(n);
            prev.push_back(newSet);
        }

        return prev;
    }
};

/*
template for backtrack
result = []
def backtrack(Path, SelectionList):
    if (meet end condition):
        print Path
        return

    for selection in SelectionList:
        select
        backtrack(Path, SelectionList)
        deselect
*/

int main(int argc, char* argv[]) {
    return 0;
}
