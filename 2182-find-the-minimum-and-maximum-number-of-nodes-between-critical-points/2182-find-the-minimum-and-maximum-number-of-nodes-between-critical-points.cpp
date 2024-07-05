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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* slow = head, *curr = slow -> next, *fast = curr -> next;
        vector<int> ans(2, -1);
        if(!fast) return ans;

        vector<int> v;
        int idx = 0;
        while(fast) {
            idx++;
            if(slow -> val < curr -> val && curr -> val > fast -> val) {
                v.push_back(idx);
            }
            else if(slow -> val > curr -> val && curr -> val < fast -> val) {
                v.push_back(idx);
            }

            slow = slow -> next;
            curr = curr -> next;
            fast = fast -> next;
        }

        if(v.size() <= 1) return ans;
        int minima = INT_MAX, maxima = INT_MIN;
        for(int i = 1; i<v.size(); i++) {
            minima = min(minima, v[i] - v[i-1]);
        }
        maxima = v[v.size() - 1] - v[0];
        ans[0] = minima, ans[1] = maxima;
        return ans;
    }
};