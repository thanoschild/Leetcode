class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, zeros1 = 0, zeros2 = 0;
        for(auto it : nums1) {
            sum1 += it;
            if(it == 0) zeros1++;
        }
        for(auto it : nums2) {
            sum2 += it;
            if(it == 0) zeros2++;
        }

        if(zeros1 == 0 && sum1 < sum2 + zeros2) return -1;
        if(zeros2 == 0 && sum2 < sum1 + zeros1) return -1;

        return max(sum1 + zeros1, sum2 + zeros2);
    }
};