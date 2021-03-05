/*
703. Kth Largest Element in a Stream (Easy)
https://leetcode.com/problems/merge-k-sorted-lists/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (const auto n: nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};

int main() {
    vector<int> num;
    KthLargest sol {1, num};
    cout << sol.add(-3) << endl;
    cout << sol.add(-2) << endl;
    cout << sol.add(-4) << endl;
    cout << sol.add(0) << endl;
    cout << sol.add(4) << endl;
}
