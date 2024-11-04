class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.size(), count = 1;
        char prev = word[0];

        for(int i = 1; i<n; i++) {
            char c = word[i];
            if(prev == c && count < 9) count++;
            else {
                ans += to_string(count);
                ans += prev;
                prev = c;
                count = 1;
            }
        }

        ans += to_string(count);
        ans += prev;
        return ans;
    }
};