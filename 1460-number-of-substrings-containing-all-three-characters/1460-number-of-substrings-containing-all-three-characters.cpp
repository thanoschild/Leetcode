class Solution {
public:
    bool isValid(vector<int> &freq) {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }

    int numberOfSubstrings(string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        vector<int> freq(3, 0);

        for(i = 0; i<n; i++) {
            freq[s[i] - 'a']++;
            while(isValid(freq)) {
                ans += (n - i);
                freq[s[j] - 'a']--;
                j++;
            }
        }

        return ans;
    }
};