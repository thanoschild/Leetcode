class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans1 = 0, ans2 = 0;
        for(auto x : nums1){
            ans1 ^= x;
        }
        for(auto x : nums2){
            ans2 ^= x;
        }
        
        return (nums1.size()%2 * ans2) ^ (nums2.size()%2 * ans1);
    }
};