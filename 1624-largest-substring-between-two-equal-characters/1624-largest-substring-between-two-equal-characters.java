class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] freq = new int[26];
        Arrays.fill(freq, -1);
        int ans = -1;

        for(int i = 0; i<s.length(); i++) {
            Character c = s.charAt(i);
            if(freq[c - 'a'] != -1) {
                ans = Math.max(ans, i - freq[c - 'a'] - 1);
                continue;
            }
            freq[c - 'a'] = i;
        }

        return ans;
    }
}