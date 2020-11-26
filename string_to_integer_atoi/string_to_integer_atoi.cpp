/*
Problem 8: String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int startIndex = 0;
        while (s[startIndex] == ' ') {
            startIndex++;
        }
        
        int sign = 1;
        uint64_t result = 0;
        
        if (s[startIndex] == '-') {
            sign = -1;
            startIndex++;
        } else if (s[startIndex] == '+') {
            startIndex++;
        }
        
        for (auto i = startIndex; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') break;
            result = result * 10 + static_cast<int>(s[i] - '0');
            if (result > INT32_MAX) {
                return (sign == 1) ? INT32_MAX : INT32_MIN;
            }
        }
        
        return sign * result;
    }
};

int main() {
    string s("-91283472332");
    cout << "s = " << s << endl;
    Solution sol;
    cout << "myAtoi = " << sol.myAtoi(s) << endl;
    return 0;
}
