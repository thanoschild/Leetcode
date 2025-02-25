class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        for(int i = 0; i<n; i++) arr[i] %= 2;

        vector<int> ones(n), zeros(n);
        if(arr[n-1] == 0) zeros[n-1] = 1;
        else ones[n-1] = 1;

        for(int i = n - 2; i>=0; i--) {
            if(arr[i] == 1) {
                ones[i] = (1 + zeros[i+1]) % mod;
                zeros[i] = ones[i+1];
            } else {
                ones[i] = ones[i+1];
                zeros[i] = (1 + zeros[i+1]) % mod;
            }
        }

        int ans = 0;
        for(auto it : ones) {
            ans += it;
            ans %= mod;
        }

        return ans;
    }
};