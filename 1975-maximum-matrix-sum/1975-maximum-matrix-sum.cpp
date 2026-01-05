class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minVal = INT_MAX, count = 0;
        for(auto row : matrix) {
            for(auto val : row) {
                sum += abs(val);
                if(val < 0) {
                    count++;
                }

                minVal = min(minVal, abs(val));
            }
        }

        if(count % 2) {
            sum -= minVal * 2;
        }

        return sum;
    }
};