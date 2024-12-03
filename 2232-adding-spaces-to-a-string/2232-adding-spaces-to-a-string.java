class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder ans = new StringBuilder();
        int n = s.length(), m = spaces.length, idx = 0;

        if(m > 0 && spaces[idx] == 0) {
            ans.append(" ");
            idx++;
        }

        for(int i = 0; i<n; i++) {
            char c = s.charAt(i);
            ans.append(c);
            if(idx < m && i+1 == spaces[idx]) {
                ans.append(" ");
                idx++;
            }
        }

        return ans.toString();
    }
}