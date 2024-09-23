class Solution {
    private int dfs(String s, Integer[] dp, Set<String> st, int idx) {
        if(idx >= s.length()) return 0;
        if(dp[idx] != null) return dp[idx];

        int minlen = s.length();
        String str = "";
        for(int i = idx; i<s.length(); i++) {
            str += s.charAt(i);
            int count = st.contains(str) ? 0 : str.length();
            int newCount = dfs(s, dp, st, i + 1);
            minlen = Math.min(minlen, count + newCount);
        }

        return dp[idx] = minlen;
    }

    public int minExtraChar(String s, String[] dictionary) {
        Integer[] dp = new Integer[s.length()];
        Set<String> st = new HashSet<>();

        for(String it : dictionary) {
            st.add(it);
        }

        return dfs(s, dp, st, 0);
    }
}