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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(head) {
            if(st.find(head -> val) == st.end()) {
                temp -> next = head;
                temp = temp -> next;
            }

            head = head -> next;
        }

        temp -> next = NULL;
        return dummy -> next;
    }
};