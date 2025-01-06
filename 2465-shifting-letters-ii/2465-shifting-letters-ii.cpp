class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n = s.size();
        vector<int> line(n+1, 0);
        for(auto x : sh){
           int start = x[0];
           int end = x[1] + 1;
           int dir = x[2];
           if(dir == 1){
               line[start]++;
               line[end]--;
           }
           else{
               line[start]--;
               line[end]++;
           }
        }
        
        for(int i = 1; i<n+1; i++){
            line[i] += line[i-1];
        }
        
        for(int i = 0; i<n; i++){
            int x = (line[i] + (s[i] - 'a'))%26;
            x = (x + 26)%26;
            s[i] = ('a' + x);
        }
        
        return s;
    }
};