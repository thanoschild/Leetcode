class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minAbs = INT_MAX, countNeg = 0;

        for(auto &row : matrix) {
            for(int x : row) {
                minAbs = min(minAbs, abs(x));
                if(x < 0) {
                    sum -= x;
                    countNeg++;
                } else {
                    sum += x;
                }
            }
        }

        return (countNeg & 1) ? sum - 2 * minAbs : sum;
    }
};