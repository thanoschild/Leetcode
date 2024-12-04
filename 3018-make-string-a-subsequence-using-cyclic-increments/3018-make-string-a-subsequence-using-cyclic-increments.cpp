class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;
        int n = str2.size();

        for(char c : str1) {
            if(idx < n && (str2[idx] - c + 26) % 26 <= 1) {
                idx++;
            }
        }

        return idx == n;
    }
};