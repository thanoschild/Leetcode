class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int count = 0;
        while(ss >> word) {
           count++;
           if(word.substr(0, searchWord.size()) == searchWord) return count;
        }

        return -1;
    }
};