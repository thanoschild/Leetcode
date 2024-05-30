class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> prefix(n+1, 0);

        for(int i = 1; i<n+1; i++) prefix[i] = prefix[i-1] ^ arr[i-1];

        for(int i = 0; i<n+1; i++) {
            for(int j = i + 1; j<n+1; j++) {
                if(prefix[i] == prefix[j]) {
                    ans += (j - i - 1);
                }
            }
        }

        return ans;
    }
};