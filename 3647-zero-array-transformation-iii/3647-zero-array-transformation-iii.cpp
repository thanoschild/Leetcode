class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        sort(queries.begin(), queries.end());
        vector<int> freq(n + 1, 0);
        priority_queue<int> pq;
        int curr = 0, j = 0;

        for (int i = 0; i < n; i++) {
            curr -= freq[i];
            while(j < m && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }

            while(curr < nums[i]) {
                if(pq.empty() || pq.top() < i) {
                    return -1;
                }
                freq[pq.top() + 1]++;
                pq.pop();
                curr++;
            }
        }

        return pq.size();
    }
};
