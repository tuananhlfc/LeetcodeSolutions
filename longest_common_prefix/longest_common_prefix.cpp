/*
Problem 14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix.erase(prefix.end() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main() {
    vector<string> input {"flower","flow","flight"};
    Solution sol;
    sol.longestCommonPrefix(input);
}
