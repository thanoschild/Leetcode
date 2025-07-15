class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool isConsonant(char c) {
        c = tolower(c);
        return isalpha(c) && !isVowel(c);
    }

    bool isValid(string word) {
        if (word.length() < 3)
            return false;

        bool hasVowel = false, hasConsonant = false;

        for (char c : word) {
            if (isdigit(c) || isVowel(c) || isConsonant(c)) {
                if (isVowel(c))
                    hasVowel = true;
                else if (isConsonant(c))
                    hasConsonant = true;
            } else {
                return false; 
            }
        }

        return hasVowel && hasConsonant;
    }
};