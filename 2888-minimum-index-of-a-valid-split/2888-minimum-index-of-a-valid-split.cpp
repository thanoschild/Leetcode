class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums) mp[it]++;

        int dominant = -1, occurance = 0;
        for(auto it : mp) {
            if(it.second > occurance) {
                dominant = it.first;
                occurance = it.second;
            }
        }
        
        int count = 0, n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] == dominant) count++;
            if(count*2 > (i+1) && (occurance - count)*2 > (n - i - 1)) return i;
        }

        return -1;
    }
};