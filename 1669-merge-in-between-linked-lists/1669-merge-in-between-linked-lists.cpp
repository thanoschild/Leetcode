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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail = list2;
        while(tail->next) {
            tail = tail->next;
        }

        ListNode* prev = NULL, *curr = list1;
        for(int i = 0; i<a; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = list2;
        for(int i = a; i<=b; i++) {
            curr = curr->next;
        }

        tail->next = curr;
        return list1;
    }
};