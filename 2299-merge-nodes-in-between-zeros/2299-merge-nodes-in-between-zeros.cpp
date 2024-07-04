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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = new ListNode(-1);
        ListNode* curr = temp;
        
        int sum = 0;
        while(head -> next) {
            head = head -> next;
            if(head -> val == 0) {
                curr -> next = new ListNode(sum);
                sum = 0;
                curr = curr -> next;
            }
            else {
                sum += head -> val;
            }
        }

        return temp -> next;
    }
};