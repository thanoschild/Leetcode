class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 1) return 1;

        vector<int> freq(256, -1);
        int start = -1, count = 0;
        for(int i = 0; i<n; i++) {
            if(freq[s[i]] > start) {
                start = freq[s[i]];
            }

            freq[s[i]] = i;
            count = max(count, i - start);
        }

        return count;
    }
};