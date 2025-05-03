class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> ans(7), a(7), b(7);
        int n = tops.size();
        for(int i = 0; i<n; i++){
            a[tops[i]]++;
            b[bottoms[i]]++;
            if(tops[i] == bottoms[i]) ans[tops[i]]++;
        }
        for(int i = 0; i<7; i++){
            if(a[i]+b[i] - ans[i] == n){
                return n - max(a[i], b[i]);
            }
        }
        return -1;
    }
};