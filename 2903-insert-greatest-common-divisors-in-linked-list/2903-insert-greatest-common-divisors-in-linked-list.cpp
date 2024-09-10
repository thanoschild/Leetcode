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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr -> next) {
            int val = __gcd(curr -> val, curr -> next -> val);
            ListNode* temp = curr -> next;
            ListNode* newNode = new ListNode(val);
            curr -> next = newNode;
            newNode -> next = temp;
            curr = temp;
        }

        return head;
    }
};