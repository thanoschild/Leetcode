class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int n : nums) {
            if(n < k) return -1;
            else if(n > k) st.insert(n);
        }

        return st.size();
    }
};