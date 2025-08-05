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
        if (!head || !head->next) return;
        ListNode* fast = head, *slow = head;

       while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow -> next;
        slow -> next = NULL;

        ListNode* nextNode, *prevNode = NULL;
        while(second) {
            nextNode = second -> next;
            second -> next = prevNode;
            prevNode = second;
            second = nextNode;
        }

        ListNode* first = head;
        second = prevNode;
        while(second) {
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;

            first -> next = second;
            second -> next = temp1;

            first = temp1;
            second = temp2;
        }

    }
};