class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int max_count = 0;
        for(auto it : tasks) {
            mp[it]++;
            max_count = max(max_count, mp[it]);
        }

        int ans = (max_count - 1) * (n + 1);
        for(auto it : mp) {
            if(it.second == max_count) ans++;
        }

        return max(ans, (int)tasks.size());
    }
};