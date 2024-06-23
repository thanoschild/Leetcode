class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, prev = 0, n = nums.size();
        multiset<int> st;
        for(int i = 0; i<n; i++) {
            st.insert(nums[i]);
            if(*st.rbegin() - *st.begin() > limit) st.erase(st.find(nums[prev++]));
            ans = max(ans, (int)st.size());
        }

        return ans;
    }
};