class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int mod = 1e9 + 7;
        for(int i = 0; i<31; i++) {
            if(n >> i & 1) powers.push_back(1 << i);
        }
        
        vector<int> ans;
        for(auto it : queries) {
            int i = it[0];
            long long pro = powers[i++];
            while(i <= it[1]) {
                pro = (pro * powers[i]) % mod;
                i++;
            }

            ans.push_back(pro);
        }

        return ans;
    }
};
