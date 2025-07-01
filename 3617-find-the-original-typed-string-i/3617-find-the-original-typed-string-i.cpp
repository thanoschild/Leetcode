class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1, ans = 0;
        for(int i = 1; i<word.size(); i++) {
            if(word[i] == word[i-1]) count++;
            else {
                ans += (count - 1);
                count = 1;
            }
        }
        if(count > 1) ans += (count - 1);

        return ans + 1;
    }
};