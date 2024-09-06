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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        ListNode* curr = new ListNode(-1);
        curr -> next = head;
        ListNode* dummy = curr;
        
        while(dummy -> next) {
            int nodeVal = dummy -> next -> val;
            if(st.find(nodeVal) != st.end()) {
                if(dummy -> next -> next) dummy -> next = dummy -> next -> next;
                else {
                    dummy -> next = NULL;
                    break;
                }
            }
            else dummy = dummy -> next;
        }

        return curr -> next;
    }
};