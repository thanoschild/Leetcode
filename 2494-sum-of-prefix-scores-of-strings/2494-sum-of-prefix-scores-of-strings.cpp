class Trie {
public:
    Trie *child[26] = {};
    int visited = 0;

    void insert(string s, Trie *root) {
        Trie *node = root;
        for(char c : s) {
            if(!node -> child[c - 'a']) node -> child[c - 'a'] = new Trie();
            node -> child[c - 'a'] -> visited++;
            node = node -> child[c - 'a'];
        }
    }

    int count_prefix(string s, Trie *root) {
        Trie *node = root;
        int val = 0;
        for(char c : s) {
            val += node -> child[c - 'a'] -> visited;
            node = node -> child[c - 'a'];
        }
        return val;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root = new Trie();
        for(string s : words) {
            root -> insert(s, root);
        }

        vector<int> ans;
        for(string s : words) {
            ans.push_back(root -> count_prefix(s, root));
        }

        return ans;
    }
};