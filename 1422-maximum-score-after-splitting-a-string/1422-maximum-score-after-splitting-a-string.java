class Solution {
    public int maxScore(String s) {
       int ones = 0, zeros = 0, ans = Integer.MIN_VALUE;
        for(int i = 0; i<s.length(); i++) {
            if(s.charAt(i) == '0') zeros++;
            else ones++;
            if(i != s.length() - 1) ans = Math.max(ans, zeros - ones);
        }
        
        return ans + ones;
    }
}