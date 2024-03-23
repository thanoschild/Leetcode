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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* fast = head, *slow = head, *prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        fast = slow;
        prev = NULL;
        
        while(fast) {
            ListNode* temp = fast->next;
            fast->next = prev;
            prev = fast;
            fast = temp;
        }

        slow = head, fast = prev;
        prev = NULL;
        while(slow && fast) {
            prev = slow;
            ListNode* temp1 = slow->next;
            ListNode* temp2 = fast->next;
            slow->next = fast;
            fast->next = temp1;
            slow = temp1;
            fast = temp2;
        }

        if(fast) prev->next->next = fast;
    }
};