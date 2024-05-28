class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), i = 0, j = 0;
        while(i < n) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            maxCost -= abs(a - b);
            if(maxCost < 0) {
                int a1 = s[j] - 'a';
                int b1 = t[j] - 'a';
                j++;
                maxCost += abs(a1 - b1);
            }
            i++;
        }

        return i - j;
    }
};