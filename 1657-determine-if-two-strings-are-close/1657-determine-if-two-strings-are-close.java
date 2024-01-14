class Solution {
    public boolean closeStrings(String word1, String word2) {
        if(word1.length() != word2.length()) return false;
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        HashSet<Character> seen1 = new HashSet<>();
        HashSet<Character> seen2 = new HashSet<>();
        
        for(int i = 0; i<word1.length(); i++) {
            freq1[word1.charAt(i) - 'a']++;
            freq2[word2.charAt(i) - 'a']++;

            seen1.add(word1.charAt(i));
            seen2.add(word2.charAt(i));
        }

        Arrays.sort(freq1);
        Arrays.sort(freq2);

        return Arrays.equals(freq1, freq2) && seen1.equals(seen2);
    }
}