class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp;
        for(auto it : target) mp[it]++;
        for(auto it : arr) {
            mp[it]--;
            if(mp[it] < 0) return false;
        }

        return true;
    }
};