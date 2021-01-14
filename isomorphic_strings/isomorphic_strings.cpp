/*
Problem 204. Count Primes (Easy)
https://leetcode.com/problems/count-primes/
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> sdict, tdict;
        for (int i = 0; i < s.size(); ++i) {
            cout << i << " " << s[i] << " " << t[i] << endl;
            if (sdict.count(s[i]) && tdict.count(t[i])) {
                if (!tdict.count(t[i])) return false;
                if (sdict[s[i]] != tdict[t[i]]) return false;
            } else if (sdict.count(s[i]) || tdict.count(t[i])) {
                return false;
            } else {
                sdict[s[i]] = i;
                tdict[t[i]] = i;
            }
        }
        return true;
    }
};

int main() {
    string s("badc"), t("baba");
    Solution sol;
    cout << sol.isIsomorphic(s, t) << endl;
}
