class Solution {
    public char kthCharacter(int k) {
        String s = "a";

        while (s.length() < k) {
            StringBuilder curr = new StringBuilder();
            for (char c : s.toCharArray()) {
                int idx = (c - 'a' + 1) % 26;
                char a = (char) ('a' + idx);
                curr.append(a);
            }
            s += curr.toString();
        }

        return s.charAt(k - 1);
    }
}