/*
Problem 19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

#include <iostream>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0, head);
        auto ptr1 = head, ptr2 =  dummy;
        for (int i = 1; i < n; ++i) ptr1 = ptr1->next;
        // if (!ptr1) return head;
        while (ptr1->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        auto nodeRemoved = ptr2->next;
        ptr2->next = nodeRemoved->next;
        delete nodeRemoved;
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    vector<int> input {1, 2, 3, 4, 5};
    ListNode* head = new ListNode(input[0]);
    auto node = head;
    for (int i = 1; i < input.size(); ++i) {
        node->next = new ListNode(input[i]);
        node = node->next;
    }

    cout << "Input : ";
    node = head;
    while (node) {
        cout << node->val << '\t';
        node = node->next;
    }
    cout << "\nOutput: ";
    Solution sol;
    auto ans = sol.removeNthFromEnd(head, 5);
    while (ans) {
        cout << ans->val << '\t';
        ans = ans->next;
    }
    cout << endl;
}
