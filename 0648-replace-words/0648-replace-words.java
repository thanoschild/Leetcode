class Trie {
    Trie[] children;
    boolean isEnd;

    public Trie() {
        children = new Trie[26];
        isEnd = false;
    }
}

class Solution {
    Trie root;

    private void insert(String word) {
        Trie node = root;
        for(char c : word.toCharArray()) {
            int i = c - 'a';
            if(node.children[i] == null) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
        node.isEnd = true;
    }

    private String search(String word) {
        Trie node = root;
        String curr = "";
        for(char c : word.toCharArray()) {
            int i = c - 'a';
            curr += c;
            if(node.children[i] == null) return word;
            else if(node.children[i].isEnd) return curr;
            else node = node.children[i];
        }

        return word;
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        root = new Trie();
        for(String word : dictionary) {
            insert(word);
        }

        StringBuilder ans = new StringBuilder();
        String[] input = sentence.split(" ");
        for(String s : input) {
            ans.append(search(s));
            ans.append(" ");
        }

        return ans.toString().trim();
    }
}