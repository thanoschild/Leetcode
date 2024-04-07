class Solution {
public:
    bool checkValidString(string s) {
        int leftmin = 0, leftmax = 0;
        for(char c : s) {
            if(c == '(') leftmin++, leftmax++;
            else if(c == ')') leftmin--, leftmax--;
            else leftmax++, leftmin--;
            if(leftmax < 0) return false;
            if(leftmin < 0) leftmin = 0;
        }

        return leftmin == 0;
    }
};