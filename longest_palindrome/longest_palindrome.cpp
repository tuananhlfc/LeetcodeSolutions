/*
Problem 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans, palind;
        for (int i = 0; i < s.size(); ++i) {
            palind = longestPanlindromeAroundCenter(s, i, i);
            if (palind.size() > ans.size()) ans = palind;
            palind = longestPanlindromeAroundCenter(s, i, i + 1);
            if (palind.size() > ans.size()) ans = palind;
        }
        return ans;
    }
    
    string longestPanlindromeAroundCenter(const string& s, int lo, int hi) {
        // if (s[lo--] != s[hi++]) return "";
        while (lo >= 0 && hi < s.size()) {
            if (s[lo] != s[hi]) break;
            lo--;
            hi++;
        }
        // cout << lo + 1 << '\t' << hi - lo - 1 << endl;
        return s.substr(lo + 1, hi - lo -1);
    }
};

int main() {
    string input {"aabbcc"};
    Solution sol;
    cout << sol.longestPalindrome(input) << endl;
}
