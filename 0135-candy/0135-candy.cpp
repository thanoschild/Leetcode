class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 1);
        
        for(int i = 1; i<n; i++){
            if(arr[i] > arr[i-1]){
                left[i] = left[i-1] + 1;
            }
        }
        int ans = left[n-1];
        for(int i = n-2; i>=0; i--){
           if(arr[i] > arr[i+1]){
             left[i] = max(left[i], left[i+1] + 1);
           }
           ans += left[i];
        }
        return ans;
    }
};