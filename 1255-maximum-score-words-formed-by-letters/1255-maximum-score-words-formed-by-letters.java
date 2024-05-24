class Solution {
    int solve(String[] words, int[] count, int[] score, int idx) {
        int max = 0;
        for(int i = idx; i<words.length; i++) {
            int ans = 0;
            boolean flag = true;
            for(char c : words[i].toCharArray()) {
                count[c - 'a']--;
                ans += score[c - 'a'];
                if(count[c - 'a'] < 0) flag = false;
            }
            if(flag) {
                ans += solve(words, count, score, i + 1);
                max = Math.max(ans, max);
            }
            for(char c : words[i].toCharArray()) {
                count[c - 'a']++;
                ans = 0;
            }
        }
        return max;
    }

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int n = words.length, m = letters.length, p = score.length;
        if(words == null || n == 0 || letters == null || m == 0 || score == null || p == 0) return 0;
        int[] count = new int[p];
        for(char c : letters) count[c - 'a']++;

        int ans = solve(words, count, score, 0);
        return ans;
    }
}