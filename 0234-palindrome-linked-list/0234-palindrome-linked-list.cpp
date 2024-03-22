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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head, *prev = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        if(fast) fast = slow->next;
        else fast = slow;
        slow = prev;

        while(fast && slow) {
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};