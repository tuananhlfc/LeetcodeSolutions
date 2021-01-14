/*
Problem 204. Count Primes (Easy)
https://leetcode.com/problems/count-primes/
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> notPrimes (n, 0);
        for (int i = 2; i <= sqrt(n); ++i) {
            if (notPrimes[i]) continue;
            cout << i << endl;
            for (int j = 2; j * i < n; ++j) {
                notPrimes[j * j] = 1;
                cout << j << endl;
            }
        }
        for (int i = 2; i < n; ++i) {
            if (!notPrimes[i]) {
                // cout << i << endl;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    int input = 10;
    Solution sol;
    cout << sol.countPrimes(input) << endl;
}
