class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    long long atLeastK(string word, int k) {
        long long ans = 0;
        int n = word.size(), j = 0, ant = 0;
        unordered_map<char, int> mp;

        for(int i = 0; i<n; i++) {
            if(isVowel(word[i])) mp[word[i]]++;
            else ant++;

            while(mp.size() == 5 && ant >= k) {
                ans += n - i;
                if(isVowel(word[j])) {
                    mp[word[j]]--;
                    if(mp[word[j]] == 0) mp.erase(word[j]);
                } else ant--;
                j++;
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
       return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};