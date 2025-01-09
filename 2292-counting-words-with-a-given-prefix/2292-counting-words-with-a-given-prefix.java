class Solution {
    boolean check(String word, String prefix) {
        int n = word.length(), m = prefix.length();
        if(m > n) return false;
        for(int i = 0; i<m; i++) {
            char a = word.charAt(i);
            char b = prefix.charAt(i);
            if(a != b) return false;
        }
        return true;
    }

    public int prefixCount(String[] words, String pref) {
        int n = words.length, ans = 0;
        for(int i = 0; i<n; i++) {
            if(check(words[i], pref)) ans++;
        }

        return ans;
    }
}