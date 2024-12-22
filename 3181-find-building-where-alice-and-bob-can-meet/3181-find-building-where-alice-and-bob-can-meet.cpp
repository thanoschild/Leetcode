class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<int> ans(m, -1);
        unordered_map<int, vector<pair<int,int>>> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i<m; i++) {
            int left = queries[i][0], right = queries[i][1];
            if(left > right) swap(left, right);
            if(left == right || heights[right] > heights[left]) ans[i] = right;
            else mp[right].push_back({max(heights[left], heights[right]), i});
        }

        for(int i = 0; i<n; i++) {
            if(mp.count(i)) {
                for(auto it : mp[i]) {
                    pq.push(it);
                }
            }

            while(!pq.empty() && heights[i] > pq.top().first) {
                auto [h, idx] = pq.top();
                pq.pop();
                ans[idx] = i;
            }
        }

        return ans;
    }
};