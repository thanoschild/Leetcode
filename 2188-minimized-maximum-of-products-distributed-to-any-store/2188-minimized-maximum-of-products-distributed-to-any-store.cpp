class Solution {
public:
    bool isPossible(vector<int> &nums, int mid, int n){
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%mid){
                count += nums[i]/mid + 1;
            }
            else{
                count += nums[i]/mid;
            }
        }
        return count<=n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = 0;
        for(int i = 0; i<quantities.size(); i++){
            hi = max(hi, quantities[i]);
        }
        int ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(quantities, mid, n)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};