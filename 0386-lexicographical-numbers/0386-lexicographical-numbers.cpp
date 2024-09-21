class Solution {
public:
    void dfs(int curr, int n, vector<int> &ans) {
        if(curr > n) return;
        ans.push_back(curr);
        for(int i = 0; i<10; i++) {
            if(10 * curr + i > n) return;
            dfs(10 * curr + i, n, ans);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i<10; i++) {
            dfs(i, n, ans);
        }

        return ans;
    }
};