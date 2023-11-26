class Solution {
    private boolean isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }

    public String sortVowels(String s) {
        int[] freq = new int[128];
        for(int i = 0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(isVowel(c)) {
                freq[(int)c]++;
            }
        }

        StringBuilder ans = new StringBuilder();
        int idx = 0;
        for(int i = 0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(isVowel(c)) {
                while(freq[idx] == 0) idx++;
                ans.append((char)idx);
                freq[idx]--;
            }
            else {
                ans.append(c);
            }
        }

        return ans.toString();
    }
}