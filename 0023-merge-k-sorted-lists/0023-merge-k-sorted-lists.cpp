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
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
       if(!list1) return list2;
       if(!list2) return list1;

       if(list1 -> val < list2 -> val) {
            list1 -> next = mergeList(list1 -> next, list2);
            return list1;
       } else {
            list2 -> next = mergeList(list1, list2 -> next);
            return list2;
       }
    }

    ListNode* dac(vector<ListNode*> &lists, int left, int right) {
        if(left == right) return lists[left];

        int mid = (right - left)/2 + left;
        ListNode* l1 = dac(lists, left, mid);
        ListNode* l2 = dac(lists, mid + 1, right);

        return mergeList(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        if(n == 1) return lists[0];

        return dac(lists, 0, n-1);
    }
};