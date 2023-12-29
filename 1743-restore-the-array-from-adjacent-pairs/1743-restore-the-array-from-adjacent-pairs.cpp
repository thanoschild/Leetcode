class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;

        for(auto it : nums) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        int start = INT_MIN;
        for(auto it : mp) {
            if(it.second.size() == 1) {
                start = it.first;
                break;
            }
        } 

        int prev = INT_MIN;
        vector<int> ans;
        ans.push_back(start);

        for(int i = 0; i<nums.size(); i++) {
            vector<int> v = mp[start];
            int curr = (v[0] == prev) ? v[1] : v[0];
            ans.push_back(curr);
            prev = start;
            start = curr;
        }

        return ans;
    }
};