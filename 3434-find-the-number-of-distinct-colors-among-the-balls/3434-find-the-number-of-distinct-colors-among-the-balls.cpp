class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colors, balls;
        vector<int> ans;

        int dist = 0;
        for(auto it : queries) {
            int x = it[0], y = it[1];
            if(balls.count(x)) {
                if(--colors[balls[x]] == 0) dist--;
            }
            balls[x] = y;
            if(++colors[y] == 1) dist++;
            ans.push_back(dist);
        }

        return ans;
    }
};