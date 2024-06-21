class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if (n == 1) return 1;

        int[] freq = new int[256];
        Arrays.fill(freq, -1);
        int start = -1, count = 0;

        for (int i = 0; i < n; i++) {
            if (freq[s.charAt(i)] > start) {
                start = freq[s.charAt(i)];
            }

            freq[s.charAt(i)] = i;
            count = Math.max(count, i - start);
        }

        return count;
    }
}