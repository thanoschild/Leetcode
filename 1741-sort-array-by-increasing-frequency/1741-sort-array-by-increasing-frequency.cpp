class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans(nums.begin(), nums.end());
        for(auto num : nums) mp[num]++;

        sort(ans.begin(), ans.end(), [&mp](int a, int b) {
            int freqA = mp[a], freqB = mp[b];
            if(freqA == freqB) return a > b;
            return freqA < freqB;
        });

        return ans;
    }
};