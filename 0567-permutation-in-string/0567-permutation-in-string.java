class Solution {
    private boolean check(int[] freq1, int[] freq2) {
        for(int i = 0; i<26; i++) {
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        for(int i = 0; i<n; i++) freq1[s1.charAt(i) - 'a']++;
        for(int i = 0; i<n; i++) freq2[s2.charAt(i) - 'a']++;

        if(check(freq1, freq2)) return true;
        for(int i = n; i<m; i++) {
            freq2[s2.charAt(i - n) - 'a']--;
            freq2[s2.charAt(i) - 'a']++;
            if(check(freq1, freq2)) return true;
        }

        return false;
    }
}