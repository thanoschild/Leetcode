class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> pos(26, 0);
        for(int i = n - 1; i>=0; i--) {
            if(pos[s[i] - 'a'] == 0) pos[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int len = 0, position = -1;
        for(int i = 0; i<n; i++) {
            position = max(position, pos[s[i] - 'a']);
            len++;
            if(position == i) {
                ans.push_back(len);
                len = 0;
                position = -1;
            }
        }

        return ans;
    }
};