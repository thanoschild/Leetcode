class Solution {
    public List<String> commonChars(String[] words) {
        int[] seen = new int[26];
        Arrays.fill(seen, Integer.MAX_VALUE);
        
        for(String s : words) {
            int[] count = new int[26];
            for(char c : s.toCharArray()) {
                count[c - 'a']++;
            }
            for(int i = 0; i<26; i++) {
                seen[i] = Math.min(seen[i], count[i]);
            }
        }

        List<String> ans = new ArrayList<>();
        for(int i = 0; i<26; i++) {
            for(int j = 0; j<seen[i]; j++) {
                ans.add(Character.toString((char)('a' + i)));
            }
        }

        return ans;
    }
}