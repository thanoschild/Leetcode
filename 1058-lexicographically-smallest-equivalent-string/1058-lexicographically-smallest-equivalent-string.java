class UnionFind {
    int[] parent;
    public UnionFind() {
       parent = new int[26];
       for(int i = 0; i<26; i++) {
          parent[i] = -1;
       }
    }

    public int findParent(int x) {
        if(parent[x] == -1) return x;
        return parent[x] = findParent(parent[x]);
    }

    public void makeUnion(int x, int y) {
        int a = findParent(x);
        int b = findParent(y);

        if(a != b) {
            parent[Math.max(a, b)] = Math.min(a, b);
        }
    }
}

class Solution {
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        UnionFind obj = new UnionFind();
        int n = s1.length();

        for(int i = 0; i<n; i++) {
            int a = s1.charAt(i) - 'a';
            int b = s2.charAt(i) - 'a';
            obj.makeUnion(a, b);
        }

        String ans = "";
        for(char c : baseStr.toCharArray()) {
            char a = (char) (obj.findParent(c - 'a') + 'a');
            ans += a;
        }

        return ans;
    }
}