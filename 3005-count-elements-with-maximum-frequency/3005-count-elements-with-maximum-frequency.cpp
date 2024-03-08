class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0, max_freq = 0;
        for(auto it : nums) {
           mp[it]++;

           if(mp[it] > max_freq) {
               max_freq = mp[it];
               count = 0;
           }

           if(mp[it] == max_freq) count++;
        }

        return count*max_freq;
    }
};