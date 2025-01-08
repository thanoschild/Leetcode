class Solution {
     private boolean check(String a, String b) {
        int n = a.length();
        int m = b.length();
        
        if (n > m) {
            return false;
        }
        
        return b.startsWith(a) && b.endsWith(a);
    }
    
    public int countPrefixSuffixPairs(String[] words) {
        int n = words.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(words[i], words[j])) {
                    ans++;
                }
            }
        }

        return ans;
    }
}