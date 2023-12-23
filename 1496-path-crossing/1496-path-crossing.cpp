class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> moves;
        moves['E'] = {1, 0};
        moves['W'] = {-1, 0};
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};

        set<pair<int, int>> st;
        st.insert({0, 0});
        int x = 0, y = 0;

        for(char c : path) {
            pair<int, int> curr = moves[c];
            x += curr.first;
            y += curr.second;

            if(st.find({x, y}) != st.end()) return true;

            st.insert({x, y});
        }

        return false;
    }
};