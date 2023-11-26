class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }

    string sortVowels(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int freq[128] = {0};
        for(char c : s) {
            if(isVowel(c)) {
                freq[(int)c]++;
            }
        }

        int idx = 0;
        for(int i = 0; i<s.size(); i++) {
            if(isVowel(s[i])) {
                while(freq[idx] == 0) idx++;
                s[i] = (char)idx;
                freq[idx]--;
            }
        }

        return s;
    }
};