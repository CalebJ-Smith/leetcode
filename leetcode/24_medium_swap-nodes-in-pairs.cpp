// https://leetcode.com/problems/swap-nodes-in-pairs/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode* newTrailer = swapPairs(head->next->next);
        ListNode* second = head->next;
        head->next = newTrailer;
        second->next = head;
        return second;
    }
};