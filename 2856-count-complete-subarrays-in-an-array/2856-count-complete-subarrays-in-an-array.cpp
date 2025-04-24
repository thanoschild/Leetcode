class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0;

        for(int i = 0, j = 0; i<n && j < n; i++) {
           mp[nums[i]]++;
           while(mp.size() == st.size()) {
              ans += (n - i);
              mp[nums[j]]--;
              if(mp[nums[j]] == 0) mp.erase(nums[j]);
              j++;
           }
        }

        return ans;
    }
};

/*
1 3 1 2 2
0 1 2 3 4

n - i + 1 = 2
n - i + 1 = 2;

*/