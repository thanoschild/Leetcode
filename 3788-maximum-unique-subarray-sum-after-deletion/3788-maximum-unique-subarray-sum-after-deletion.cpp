class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int sum = 0, maxVal = INT_MIN;
        for (int it : nums) {
            if (it > 0) {
                if (st.find(it) == st.end()) {
                    sum += it;
                    st.insert(it);
                }
            } else {
                maxVal = max(maxVal, it);
            }
        }

        if (sum == 0)
            return maxVal;

        return sum;
    }
};