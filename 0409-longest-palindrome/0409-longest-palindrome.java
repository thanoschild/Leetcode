class Solution {
    public int longestPalindrome(String s) {
        int[] lower = new int[26];
        int[] upper = new int[26];

        for (char c : s.toCharArray()) {
            if (Character.isLowerCase(c)) {
                lower[c - 'a']++;
            } else {
                upper[c - 'A']++;
            }
        }

        int result = 0;
        int hasOdd = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] % 2 == 0) {
                result += lower[i];
            } else {
                result += lower[i] - 1;
                hasOdd = 1;
            }

            if (upper[i] % 2 == 0) {
                result += upper[i];
            } else {
                result += upper[i] - 1;
                hasOdd = 1;
            }
        }

        return result + hasOdd;
    }
}