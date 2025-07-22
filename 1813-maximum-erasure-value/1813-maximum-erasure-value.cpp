class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0, start = 0, sum = 0;

        for(int end = 0; end < nums.size();) {
            if(st.find(nums[end]) != st.end()) {
               sum -= nums[start];
               st.erase(nums[start]);
               start++;
               continue;
            }

            sum += nums[end];
            ans = max(ans, sum);
            st.insert(nums[end]);
            end++;
        }

        return ans;
    }
};