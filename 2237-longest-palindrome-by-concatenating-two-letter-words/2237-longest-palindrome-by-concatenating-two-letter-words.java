class Solution {
    public int longestPalindrome(String[] words) {
        int[][] freq = new int[26][26];
        int ans = 0;

        for(String word : words) {
            int a = word.charAt(0) - 'a', b = word.charAt(1) - 'a';
            if(freq[b][a] >= 1) {
                ans += 4;
                freq[b][a]--;
            } else {
                freq[a][b]++;
            }
        }

        for(int i = 0; i<26; i++) {
            if(freq[i][i] >= 1) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
}