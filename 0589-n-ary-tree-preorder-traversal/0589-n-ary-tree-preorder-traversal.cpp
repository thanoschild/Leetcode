/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<Node*> st;
        st.push(root);

        while(!st.empty()) {
            Node* t = st.top();
            st.pop();

            ans.push_back(t->val);
            int n = t->children.size();
            for(int i = n - 1; i>=0; i--) {
                st.push(t->children[i]);
            }
        }

        return ans;
    }
};