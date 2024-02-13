class Solution {
public:
    bool check(string s) {
        int i = 0, j = s.size() - 1;
        while(i<=j) {
            if(s[i] == s[j]) i++, j--;
            else return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string s : words) {
            if(check(s)) return s;
        }
        return "";
    }
};