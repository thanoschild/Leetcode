class UnionFind {
    public:
    vector<int> parent;

    UnionFind() {
       parent.resize(26, -1);
    }

    int findParent(int x) {
        if(parent[x] == -1) return x;
        return parent[x] = findParent(parent[x]);
    }

    void makeUnion(int x, int y) {
        int a = findParent(x);
        int b = findParent(y);
        if(a != b) parent[max(a, b)] = min(a, b);
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind obj = UnionFind();
        int n = s1.size();
        for(int i = 0; i<n; i++) {
            obj.makeUnion(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";
        for(char c : baseStr) {
            ans += (obj.findParent(c - 'a') + 'a');
        }

        return ans;
    }
};