class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        auto comp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq;

        for(int i = 0; i<n; i++) {
            pq.push({nums[i], i});
        }

        while(k--) {
            auto[num, idx] = pq.top();
            pq.pop();
            pq.push({num*multiplier, idx});
        }

        vector<int> ans(n);
        while(!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            ans[idx] = num;
        }

        return ans;
    }
};