#include <cstdint>
#include <string>

class Solution {
public:
    int convert(char c) {
        if (c == 73)
            return 1;
        else if(c == 86)
            return 5;
        else if(c == 88)
            return 10;
        else if(c == 76)
            return 50;
        else if(c == 67)
            return 100;
        else if(c == 68)
            return 500;
        else
            return 1000;
    }
    uint64_t romanToInt(string s) {
        uint64_t result = 0;
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == 73 && (s[i+1] == 86 || s[i+1] == 88))
                result -= convert(s[i]);
            else if(s[i] == 88 && (s[i+1] == 76 || s[i+1] == 67))
                result -= convert(s[i]);
            else if(s[i] == 67 && (s[i+1] == 77 || s[i+1] == 68))
                result -= convert(s[i]);
            else
                result += convert(s[i]);
        }
        result += convert(s[s.length()-1]);
        return result;
    }
};