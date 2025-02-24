class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> seen;

    int findBob(int bob, vector<int> &amount, int idx = 0, int count = 1) {
        if(idx == bob) {
            if(count == 1) amount[idx] /= 2;
            else amount[idx] = 0;
            return count;
        }

        seen[idx] = 1;
        for(auto it : mp[idx]) {
            if(!seen.count(it)) {
                int temp = findBob(bob, amount, it, count + 1);
                if(temp != -1) {
                    if(temp % 2) {
                        if(count > (temp + 1) / 2) amount[idx] = 0;
                        if(count == (temp + 1) / 2) amount[idx] /= 2;
                    } else {
                        if(count > temp/2) amount[idx] = 0;
                    }
                    return temp;
                }
            }
        }
        return -1;
    }

    int bestPath(vector<int> &amount, int idx = 0) {
        int ans = -1e9;
        seen[idx]++;
        for(auto it : mp[idx]) {
            if(!seen.count(it)) {
                ans = max(ans, bestPath(amount, it));
            }
        }

        if(ans == -1e9) ans = 0;
        return ans + amount[idx];
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        for(auto it : edges) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        findBob(bob, amount);
        seen.clear();
        int ans = bestPath(amount);
        return ans;
    }
};