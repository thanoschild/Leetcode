class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it : arr) {
            int rem = (it % k + k) % k;
            mp[rem]++;
        }

        for(int i = 1; i<=k/2; i++) {
            if(mp[i] != mp[k-i]) return false;
        }

        return mp[0] % 2 == 0;
    }
};