class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int ops = 0, ones = 0;
        for(int i = 0; i<n; i++) {
            ans[i] = ops;
            if(boxes[i] == '1') ones++;
            ops += ones;
        }
        ops = 0, ones = 0;
        for(int i = n - 1; i>=0; i--) {
            ans[i] += ops;
            if(boxes[i] == '1') ones++;
            ops += ones;
        }

        return ans;
    }
};