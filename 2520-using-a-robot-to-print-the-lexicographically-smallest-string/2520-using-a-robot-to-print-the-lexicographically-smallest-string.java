class Solution {
    public String robotWithString(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int lo = 0;
        StringBuilder p = new StringBuilder();
        StringBuilder t = new StringBuilder();

        for (char c : s.toCharArray()) {
            t.append(c);
            freq[c - 'a']--;

            while (lo < 26 && freq[lo] == 0) lo++;

            while (t.length() != 0 && t.charAt(t.length() - 1) - 'a' <= lo) {
                p.append(t.charAt(t.length() - 1));
                t.deleteCharAt(t.length() - 1);
            }
        }

        return p.toString();
    }
}