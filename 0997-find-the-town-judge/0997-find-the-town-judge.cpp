class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1, 0);
        for(auto it : trust) {
            indeg[it[0]]--;
            indeg[it[1]]++;
        }

        for(int i = 1; i<=n; i++) {
            if(indeg[i] == n - 1) return i;
        }

        return -1;
    }
};