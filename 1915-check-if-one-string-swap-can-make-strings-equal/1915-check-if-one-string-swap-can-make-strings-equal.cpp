class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n != m) return false;
        if(s1 == s2) return true;

        int a = -1, b = -1, count = 0;
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i]) {
                count++;
                if(a == -1) a = i;
                else if(b == -1) b = i;
            }
        }

        return count == 2 && s1[a] == s2[b] && s1[b] == s2[a];
    }
};