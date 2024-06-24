class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> pq;
        int ans = 0;

        for(int i = 0; i<n; i++) {
            while(!pq.empty() && i > pq.front() + k - 1) {
                pq.pop();
            }

            if((nums[i] + pq.size()) % 2 == 0) {
                if(i+k > n) return -1;
                ans++;
                pq.push(i);
            }
        }

        return ans;
    }
};