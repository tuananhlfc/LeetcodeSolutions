#include <cstdint>
using namespace std;

class Solution {
public:
    uint64_t fibonacci(const int number) {
        // TODO: Your code here
        if(number == 0) {
            return 0;
        } else if(number == 1) {
            return 1;
        } else {
            return (fibonacci(number-2) + fibonacci(number-1));        
        }
    }
};
