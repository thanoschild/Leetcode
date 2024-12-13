class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i<n; i++) {
            pq.push({nums[i], i});
        }

        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int num = t.first;
            int idx = t.second;

            if(nums[idx] != -1) {
                score += num;
                nums[idx] = -1;

                if(idx > 0 && nums[idx-1] != -1) nums[idx-1] = -1;
                if(idx < n - 1 && nums[idx+1] != -1) nums[idx+1] = -1;
            }
        }

        return score;
    }
};