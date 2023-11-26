class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++) {
            int k = nums[i].size();
            m = max(m, k);
            for(int j = 0; j<k; j++) {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i<n+m - 1; i++) {
            vector<int> temp = mp[i];
            for(int j = temp.size() - 1; j>=0; j--) {
                ans.push_back(temp[j]);
            }
        }
        
        return ans;
    }
};
