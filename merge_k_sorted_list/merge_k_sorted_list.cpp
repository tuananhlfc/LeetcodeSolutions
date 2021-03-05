/*
23. Merge k Sorted Lists (Hard)
https://leetcode.com/problems/merge-k-sorted-lists/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        vector<ListNode*> min_heap;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i])
                min_heap.push_back(lists[i]);
        }

        auto cmp = [] (ListNode* node, ListNode* node2) {
            return node->val > node2->val;
        };
        make_heap(min_heap.begin(), min_heap.end(), cmp);
        for (auto& v: min_heap) {
            cout << v->val << '\t';
        }
        cout << endl;

        auto head = dummy;
        while (!min_heap.empty()) {
            pop_heap(min_heap.begin(), min_heap.end(), cmp);
            head->next = new ListNode(min_heap.back()->val);
            cout << "Pop: " << min_heap.back()->val << endl;
            head = head->next;

            auto node = min_heap.back()->next;
            min_heap.pop_back();
            if (node) {
                min_heap.push_back(node);
                cout << "Push: " << node << endl;
                push_heap(min_heap.begin(), min_heap.end(), cmp);
            }

            // cout << "Pop: " << head->val << endl;
             for (auto& v: min_heap) {
                 cout << v->val << '\t';
             }
             cout << endl;
        }

        return dummy->next;
    }
};

int main() {
    vector<ListNode*> input(3);
    input[0] = new ListNode(1, new ListNode(4, new ListNode(5)));
    input[1] = new ListNode(1, new ListNode(3, new ListNode(4)));
    auto p = input[1];
    while (p) {
        cout << p->val << '\t';
        p = p->next;
    }
    cout << endl;
    input[2] = new ListNode(2, new ListNode(6));
    Solution sol;
    auto lists = sol.mergeKLists(input);
}
