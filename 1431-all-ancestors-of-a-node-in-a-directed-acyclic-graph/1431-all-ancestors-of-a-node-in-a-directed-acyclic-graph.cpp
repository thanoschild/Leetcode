class Solution {
public:
    void dfs(int x, int curr, vector<vector<int>>& ans, vector<vector<int>>& child) {
        for(auto it : child[curr]) {
            if(ans[it].size() == 0 || ans[it].back() != x) {
                ans[it].push_back(x);
                dfs(x, it, ans, child);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), child(n);
        for (auto e : edges) {
            child[e[0]].push_back(e[1]);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, i, ans, child);
        }

        return ans;
    }
};