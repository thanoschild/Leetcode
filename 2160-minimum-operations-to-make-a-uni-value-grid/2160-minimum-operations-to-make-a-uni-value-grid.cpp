class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto row : grid) {
            for(auto col : row) {
                arr.push_back(col);
            }
        }

        sort(arr.begin(), arr.end());
        for(auto it : arr) {
            if(abs(it - arr[0]) % x != 0) return -1;
        }

        int median = arr[arr.size()/2], ans = 0;

        for(auto it : arr) {
           ans += (abs(it - median)/x);
        }

        return ans;
    }
};