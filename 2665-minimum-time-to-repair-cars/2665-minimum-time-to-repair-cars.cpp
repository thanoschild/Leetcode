class Solution {
public:
    bool isValid(long long time, vector<int> &ranks, int cars) {
        long long count = 0;
        for(int rank : ranks) {
            count += sqrt(time / rank);
            if(count >= cars) return true;
        }

        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1e14, ans = 0;

        while(left <= right) {
            long long mid = (right - left)/2 + left;
            if(isValid(mid, ranks, cars)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};