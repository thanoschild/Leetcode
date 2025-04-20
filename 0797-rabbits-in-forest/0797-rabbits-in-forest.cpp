class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int it : answers) mp[it]++;

        int ans = 0;
        for(auto it : mp) {
            if(it.first > it.second) ans += (it.first + 1);
            else {
                if(it.second % (it.first + 1)) ans += ((it.second / (it.first + 1) + 1) * (it.first + 1));
                else ans += it.second;
            }
        }

        return ans;
    }
};