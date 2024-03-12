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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        ListNode* curr = dummy;
        unordered_map<int, ListNode*> mp;

        while(curr) {
            prefix += curr->val;
            mp[prefix] = curr;
            curr = curr->next;
        }

        prefix = 0;
        curr = dummy;
        while(curr) {
            prefix += curr->val;
            curr->next = mp[prefix]->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};