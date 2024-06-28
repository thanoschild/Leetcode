class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        for(auto it : roads) {
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        long long ans = 0, val = 1;
        sort(indegree.begin(), indegree.end());
        for(int x : indegree) {
            ans += (val * x);
            val++;
        }

        return ans;
    }
};