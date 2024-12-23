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
    int minSwaps(vector<int> &nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(v[i].second == i) continue;
            else {
                count++;
                swap(v[i], v[v[i].second]);
                i--;
            }
        }
        return count;
    }

    int minimumOperations(TreeNode* root) {
        if(!root) return -1;
        int ans = 0;
        queue<TreeNode*> pq;
        pq.push(root);

        while(!pq.empty()) {
            int n = pq.size();
            vector<int> curr;
            for(int i = 0; i<n; i++) {
                TreeNode* node = pq.front();
                pq.pop();

                curr.push_back(node->val);
                if(node->left) pq.push(node->left);
                if(node->right) pq.push(node->right);
            }

            ans += minSwaps(curr);
        }

        return ans;
    }
};