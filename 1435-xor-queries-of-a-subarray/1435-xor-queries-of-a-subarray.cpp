class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int _xor = 0;
        vector<int> prefixXor;
        
        for(auto it : arr) {
            _xor ^= it;
            prefixXor.push_back(_xor);
        }

        vector<int> ans;
        for(auto it : queries) {
            if(it[0] == 0) ans.push_back(prefixXor[it[1]]);
            else ans.push_back(prefixXor[it[1]] ^ prefixXor[it[0] - 1]);
        }

        return ans;
    } 
};