class Solution {
    public boolean checkVowel(char c) {
        c = Character.toLowerCase(c);
        return Character.isLetter(c) && "aeiou".indexOf(c) != -1;
    }

    boolean checkDigit(char c) {
        return Character.isDigit(c);
    }

    boolean checkConsonant(char c) {
        c = Character.toLowerCase(c);
        return Character.isLetter(c) && "aeiou".indexOf(c) == -1;
    }

    public boolean isValid(String word) {
        int n = word.length();
        if(n < 3) return false;

        boolean seenVowel = false, seenConsonant = false;
        for(char c : word.toCharArray()) {
            if(checkVowel(c) || checkDigit(c) || checkConsonant(c)) {
                if(checkVowel(c)) seenVowel = true;
                else if(checkConsonant(c)) seenConsonant = true;
            } else {
                return false;
            }
        }

        return seenVowel && seenConsonant;
    }
}