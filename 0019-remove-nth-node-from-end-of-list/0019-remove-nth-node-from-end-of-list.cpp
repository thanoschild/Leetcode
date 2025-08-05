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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        while(n > 0) {
            fast = fast -> next;
            n--;
        }

        if(!fast) return head -> next;

        while(fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode* toDelete = slow -> next;
        slow -> next = slow -> next -> next;
        delete(toDelete);

        return head;
    }
};