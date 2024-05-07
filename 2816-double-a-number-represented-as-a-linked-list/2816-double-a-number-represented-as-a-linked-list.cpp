/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int solve(ListNode* head) {
        if(!head) return 0;
        int carry = solve(head->next);

        int currVal = head->val * 2 + carry;
        head->val = currVal % 10;
        return currVal/10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = solve(head);
        if(carry != 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};