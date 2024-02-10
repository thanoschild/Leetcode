class Solution {
    private int solve(int i, int j, String s) {
        int count = 0;
        while(i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            i--; j++;
            count++;
        }

        return count;
    }
    
    public int countSubstrings(String s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i<n; i++) {
            int j = i;
            int odd = solve(i, j, s);
            int even = solve(i, j+1, s);
            ans += (odd + even);
        }

        return ans;
    }
}