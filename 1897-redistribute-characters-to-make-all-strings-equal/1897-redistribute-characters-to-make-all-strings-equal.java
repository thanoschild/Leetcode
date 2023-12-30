class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;
        int[] freq = new int[26];

        for(String word : words) {
            for(Character c : word.toCharArray()) {
                freq[c - 'a']++;
            }
        }

        for(int i = 0; i<26; i++) {
            if(freq[i]%n != 0) return false;
        }

        return true;
    }
}