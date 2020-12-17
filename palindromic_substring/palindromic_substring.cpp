/*
Problem 647. Palindromic Substrings
https://leetcode.com/problems/palindromic-substrings/
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += countSubstringsAroundCenter(s, i, i) + countSubstringsAroundCenter(s, i, i + 1);
        }
        return count;
    }

    int countSubstringsAroundCenter(const string& s, int lo, int hi) {
        int count = 0;
        while (lo >= 0 && hi < s.size()) {
            if (s[lo] != s[hi]) break;
            count++;
            lo++;
            hi--;
        }
        return count;
    }
};

class Solution2 {
public:
    int countSubstrings(string s) {
        if (s.size() <= 1) return s.size();
        if (s.size() == 2) return (s[0] == s[1]) ? 3 : 2;
        vector<vector<bool>> palindrome (s.size(), vector<bool>(s.size(), false));
        for (auto i = 0; i < s.size(); ++i) palindrome[i][i] = true;
        int count = s.size();
        for (auto i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                palindrome[i][i + 1] = true;
                count++;
            }
        }

        for (auto i = 0; i < s.size() - 2; ++i) {
            for (auto j = i + 2; j < s.size(); ++j) {
                palindrome[i][j] = (s[i] == s[j]) && palindrome[i + 1][j - 1];
                if (palindrome[i][j]) {
                    cout << i << '\t' << j << endl;
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    string input {"aaaaa"};
    Solution sol;
    cout << sol.countSubstrings(input) << endl;
}
