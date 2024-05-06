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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while(head) {
            while(!st.empty() && st.top()->val < head->val) st.pop();
            st.push(head);
            head = head->next;
        }

        ListNode* prev = NULL;
        while(!st.empty()) {
            ListNode* curr = st.top();
            st.pop();
            curr->next = prev;
            prev = curr;
        }

        return prev;
    }
};