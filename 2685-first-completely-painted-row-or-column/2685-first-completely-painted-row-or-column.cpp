class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        map<int,int> r,c;
        for(int i=0;i<arr.size();i++){
            auto x = mp[arr[i]];
            r[x.first] += 1;
            c[x.second] += 1;
            
            if(r[x.first] == mat[0].size() || c[x.second] == mat.size()) return i;
        }
        return -1;
    }
};