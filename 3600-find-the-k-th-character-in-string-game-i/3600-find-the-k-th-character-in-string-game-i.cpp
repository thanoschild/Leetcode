class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k) {
            string curr = "";
            for(char c : s) {
                curr += (char) (((c - 'a') + 1) % 26) + 'a';
            }
            s += curr;
        }
        
        return s[k-1];
    }
};