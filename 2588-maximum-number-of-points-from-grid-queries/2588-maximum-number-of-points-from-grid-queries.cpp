class Solution {
public:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];  // Min-heap based on a[0]
        }
    };
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        int queriesLength = queries.size();
        vector<pair<int,int>> sortedQueries;
        for(int i = 0; i<queriesLength; i++) sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int dirs[5] = {-1, 0, 1, 0, -1};

        vector<int> ans(queriesLength);
        int points = 0;
        for(auto [val, idx] : sortedQueries) {
            while(!pq.empty() && pq.top()[0] < val) {
               vector<int> t = pq.top();
               pq.pop();
               int curr = t[0], x = t[1], y = t[2];
               points++;
               for(int k = 0; k<4; k++) {
                   int dx = x + dirs[k];
                   int dy = y + dirs[k + 1];
                   if(dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy]) {
                      pq.push({grid[dx][dy], dx, dy});
                      visited[dx][dy] = true;
                   }
               }
            }

            ans[idx] = points;
        }
       
        return ans;
    }
};