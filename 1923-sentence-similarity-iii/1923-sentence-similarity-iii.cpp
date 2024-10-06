class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss(s1);
        string word;
        vector<string> words1;
        while(getline(ss, word, ' ')) {
            words1.push_back(word);
        }

        stringstream sss(s2);
        word = "";
        vector<string> words2;
        while(getline(sss, word, ' ')) {
            words2.push_back(word);
        }

        int n = words1.size(), m = words2.size();
        if(n > m) {
            swap(words1, words2);
            swap(n, m);
        }

        int i = 0;
        while(i < n && words1[i] == words2[i]) i++;
        while(i < n && words1[i] == words2[m - n + i]) i++;

        return i == n;
    }
};