class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<vector<int>> curr(n, vector<int>(2));

        for(int i = 0; i<n; i++) {
            curr[i][0] = score[i];
            curr[i][1] = i;
        }

        sort(curr.begin(), curr.end(), [&](vector<int> &a, vector<int> &b){
            return a[0] > b[0];
        });
        vector<string> ans(n);

        for(int i = 0; i<n; i++) {
            if(i == 0) {
                ans[curr[i][1]] = "Gold Medal";
            }
            else if(i == 1) {
                ans[curr[i][1]] = "Silver Medal";
            }
            else if(i == 2) {
                ans[curr[i][1]] = "Bronze Medal";
            }
            else {
                ans[curr[i][1]] = to_string(i + 1);
            }
        }

        return ans;
    }
};