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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head, *prev;
        while(curr) {
            len++;
            curr = curr -> next;
        } 

        int sz = len/k, rem = len % k;
        vector<ListNode*> ans(k);
        curr = head;
        
        for(int i = 0; i<k; i++) {
            if(curr) {
               ans[i] = curr;
               for(int j = 0; j<sz + (rem > 0); j++) {
                  prev = curr;
                  curr = curr -> next;
               }
               rem--;
               prev -> next = NULL;
            }
            else {
               ans[i] = NULL;
            }
        }

        return ans;
    }
};