class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
        int ans = 0, j = 0;

        for(int i = 0; i<colors.size(); i++) {
            if(i > 0 && colors[i] == colors[i-1]) j = i;
            if(i - j + 1 >= k) ans++;
        }

        return ans;
    }
};