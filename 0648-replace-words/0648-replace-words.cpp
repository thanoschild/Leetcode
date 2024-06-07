class Trie {
    public:
        Trie* children[26];
        bool isEnd;

        Trie() {
            isEnd = false;
            for(int i = 0; i<26; i++) children[i] = NULL;
        }
};

class Solution {
public:
    Trie* root;
    void insert(string word) {
        Trie* node = root;
        for(char c : word) {
            int i = c - 'a';
            if(node -> children[i] == NULL) {
                node -> children[i] = new Trie();
            }
            node = node -> children[i];
        }
        node -> isEnd = true;
    }

    string search(string word) {
        Trie* node = root;
        string curr = "";
        for(char c : word) {
            int i = c - 'a';
            curr += c;
            if(node -> children[i] == NULL) return word;
            else if(node -> children[i] -> isEnd) return curr;
            else node = node -> children[i];
        }
        
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Trie();
        for(string s : dictionary) insert(s);

        stringstream ss(sentence);
        string word;
        string result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += search(word);
        }

        return result;
    }
};