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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag;
    bool check(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        if(head -> val == root -> val) {
            ListNode* temp = head;
            return check(temp -> next, root -> left) || check(temp -> next, root -> right);
        }
        return false;
    }

    void solve(ListNode* head, TreeNode* root) {
        if(!root) return;
        ListNode* temp = head;
        if(root -> val == head -> val && check(temp, root)) {
            flag = true;
            return;
        }
        // delete temp;
        solve(head, root -> left);
        solve(head, root -> right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        flag = false;
        solve(head, root);
        return flag;
    }
};