class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while(!pq.empty()) {
            auto[x, y] = pq.top();
            pq.pop();
            while(x--) ans += y;
        }

        return ans;
    }
};