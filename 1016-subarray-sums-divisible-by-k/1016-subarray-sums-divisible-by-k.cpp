class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;

        int count = 0, sum = 0;
        for(int n : nums) {
            sum += n;
            int rem = sum % k;
            if(rem < 0) rem += k;
            if(mp.find(rem) != mp.end()) count += mp[rem];
            mp[rem]++;
        }

        return count;
    }
};