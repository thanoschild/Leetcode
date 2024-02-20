class Solution {
    public int getMaxLen(List<String> dict) {
        int maxLen = 0;
        for(String s : dict) {
            maxLen = Math.max(maxLen, (int)s.length());
        }
        return maxLen;
    }

    public boolean wordBreak(String s, List<String> dict) {
        int n = s.length();
        int m = dict.size();
        if(m == 0) return false;
        int maxLen = getMaxLen(dict);
        HashSet<String> st = new HashSet<>(dict);
        boolean[] dp = new boolean[n+1];
        dp[0] = true;

        for(int i = 1; i<=n; i++) {
            for(int j = i-1; j>=0 && j - i < maxLen; j--) {
                if(dp[j]) {
                    if(st.contains(s.substring(j, i))) dp[i] = true;
                }
            }
        }

        return dp[n];
    }
}