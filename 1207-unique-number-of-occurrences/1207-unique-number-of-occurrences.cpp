class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> ans;

        int i = 0, n = arr.size();
        while(i < n) {
            int count = 1, j;
            for(j = i + 1; j<n; j++) {
                if(arr[i] == arr[j]) count++;
                else break;
            }
            ans.push_back(count);
            i = j;
        }

        sort(ans.begin(), ans.end());
        for(int i = 0; i<ans.size() - 1; i++) {
            if(ans[i] == ans[i+1]) return false;
        }

        return true;
    }
};