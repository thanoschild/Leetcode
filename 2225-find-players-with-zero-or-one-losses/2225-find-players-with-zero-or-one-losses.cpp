class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int,int>> mp;
        for(auto it : matches) {
            mp[it[0]] = {mp[it[0]].first+1, mp[it[0]].second};
            mp[it[1]] = {mp[it[1]].first, mp[it[1]].second+1};
        }

        vector<vector<int>> ans(2);
        for(auto it : mp) {
            if(it.second.second == 0) ans[0].push_back(it.first);
            if(it.second.second == 1) ans[1].push_back(it.first);
        }

        return ans;
    }
};