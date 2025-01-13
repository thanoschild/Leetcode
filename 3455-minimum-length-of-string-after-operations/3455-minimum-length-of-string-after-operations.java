class Solution {
    public int minimumLength(String s) {
        int[] freq = new int[26];
        for(char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int ans = 0;
        for(int i = 0; i<26; i++) {
            if(freq[i] == 0) continue;
            if(freq[i] % 2 == 0) ans += 2;
            else ans += 1;
        }

        return ans;
    }
}