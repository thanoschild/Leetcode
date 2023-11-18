class Solution {
    public int countPalindromicSubsequence(String s) {
        int[] minIdx = new int[26];
        int[] maxIdx = new int[26];
        
        for(int i = 0; i<26; i++) {
            minIdx[i] = Integer.MAX_VALUE;
            maxIdx[i] = Integer.MIN_VALUE;
        }
        
        int n = s.length();
        int ans = 0;
        
        for(int i = 0; i<n; i++) {
            char c = s.charAt(i);
            minIdx[c - 'a'] = Math.min(minIdx[c - 'a'], i);
            maxIdx[c - 'a'] = Math.max(maxIdx[c - 'a'], i);
        }
        
        for(int i = 0; i<26; i++) {
            if(minIdx[i] == Integer.MAX_VALUE || maxIdx[i] == Integer.MIN_VALUE) continue;
            
            HashSet<Character> st = new HashSet<>();
            for(int j = minIdx[i] + 1; j<maxIdx[i]; j++) {
                st.add(s.charAt(j));
            }
            ans += st.size();
        }
        
        return ans;
    }
}