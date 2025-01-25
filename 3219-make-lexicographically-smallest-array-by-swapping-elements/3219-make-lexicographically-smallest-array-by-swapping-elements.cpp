class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> curr;

        for(int i = 0; i<n; i++) {
            curr.push_back({nums[i], i});
        }
        sort(curr.begin(), curr.end());

        vector<vector<pair<int,int>>> groups = {{curr[0]}};
        for(int i = 1; i<n; i++) {
            if(curr[i].first - curr[i-1].first <= limit) groups.back().push_back(curr[i]);
            else groups.push_back({curr[i]});
        }

        for(auto it : groups) {
            vector<int> idx;
            for(auto node : it) {
                idx.push_back(node.second);
            }
            sort(idx.begin(), idx.end());

            for(int i = 0; i<idx.size(); i++) {
                nums[idx[i]] = it[i].first;
            }
        }

        return nums;
    }
};