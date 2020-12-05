#include <cstdint>

class Solution {
public:
    uint64_t fibonacci(const int number) {
        // TODO: Your code here
        if(number <= 1) {
            return number;
        } else {
            return (fibonacci(number-2) + fibonacci(number-1));        
        }
    }
};
