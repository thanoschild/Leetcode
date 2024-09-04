class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<string> st;
        for(auto obs : obstacles) {
            st.insert(to_string(obs[0]) + "-" + to_string(obs[1]));
        }

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, x = 0, y = 0, ans = 0;

        for(auto c : commands) {
            if(c == -1) {
                d++;
                if(d == 4) d = 0;
            }
            else if(c == -2) {
                d--;
                if(d == -1) d = 3;
            }
            else {
                while(c-- > 0 && st.find(to_string(dirs[d][0] + x) + "-" + to_string(dirs[d][1] + y)) == st.end()) {
                    x += dirs[d][0];
                    y += dirs[d][1];
                }
            }
            ans = max(ans, x*x + y*y);
        }

        return ans;
    }
};