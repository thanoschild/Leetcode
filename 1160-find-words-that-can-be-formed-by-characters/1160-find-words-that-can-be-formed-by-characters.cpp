class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(char c : chars) mp[c]++;
        
        int ans = 0;
        for(string s : words) {
            unordered_map<char, int> curr = mp;
            int n = s.size();
            bool flag = true;
            for(int i = 0; i<n; i++) {
                char c = s[i];
                if(curr[c] > 0) {
                    curr[c]--;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) ans += n;
        }
        
        return ans;
    }
};