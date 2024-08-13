class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &curr, vector<int> &arr, int sum) {
        int n = arr.size();
        if(sum == 0) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i<n; i++) {
            if(i > idx && arr[i] == arr[i-1]) continue;
            if(sum < arr[i]) break;
            curr.push_back(arr[i]);
            solve(i + 1, curr, arr, sum - arr[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> curr;
        sort(arr.begin(), arr.end());
        solve(0, curr, arr, target);
        return ans;
    }
};