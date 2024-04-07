class Solution {
    public boolean checkValidString(String s) {
        int leftmin = 0, leftmax = 0;
        for(char c : s.toCharArray()) {
            if(c == '(') {
                leftmin++; leftmax++;
            }
            else if(c == ')') {
                leftmin--; leftmax--;
            }
            else {
                leftmin--; leftmax++;
            }
            if(leftmax < 0) return false;
            if(leftmin < 0) leftmin = 0;
        }

        return leftmin == 0;
    }
}