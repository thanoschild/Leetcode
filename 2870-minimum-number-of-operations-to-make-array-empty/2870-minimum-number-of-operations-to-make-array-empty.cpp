class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums) mp[it]++;
        int count = 0;
        
        for(auto it : mp) {
            int x = it.second;
            if(x == 1) return -1;
            count += x / 3 + (x % 3 != 0); 
        }

        return count;
    }
};