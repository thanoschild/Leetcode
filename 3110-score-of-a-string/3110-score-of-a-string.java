class Solution {
    public int scoreOfString(String s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i<n-1; i++) {
            int a = s.charAt(i) - 'a';
            int b = s.charAt(i+1) - 'a';
            ans += Math.abs(a - b);
        }

        return ans;
    }
}