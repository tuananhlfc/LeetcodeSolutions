#include <cstdint>
#include <vector>

class Solution {
public:
    uint64_t fibonacci1(const int number) {
        // TODO: Your code here
        if (number == 0) return 0;
        if (number == 1) return 1;
        return fibonacci1(number - 1) + fibonacci1(number - 2);
    }

    uint64_t fibonacci2(const int number) {
        // TODO: Your code here
        if (number == 0) return 0;
        if (number == 1) return 1;
        std::vector<uint64_t> fibo (number + 1);
        fibo[0] = 0;
        fibo[1] = 1;
        for (int i = 2; i < fibo.size(); ++i) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        return fibo[number];
    }

    uint64_t fibonacci3(const int number) {
        // TODO: Your code here
        if (number == 0) return 0;
        if (number == 1) return 1;
        uint64_t a = 0, b = 1, c;
        for (int i = 1; i < number; ++i) {
            c = b;
            b = a + b;
            a = c;
        }
        return b;
    }
};
