class Solution {
    public int lengthOfLastWord(String s) {
        int idx = s.length() - 1, ans = 0;
        while(idx >= 0 && s.charAt(idx) == ' ') idx--;
        while(idx >= 0 && s.charAt(idx) != ' ') {
            idx--;
            ans++;
        }

        return ans;
    }
}