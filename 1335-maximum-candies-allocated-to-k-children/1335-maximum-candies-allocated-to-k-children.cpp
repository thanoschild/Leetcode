class Solution {
public:
    bool isValid(int mid, vector<int>&candies, long long k) {
        long long count = 0;
        for(int n : candies) {
            count += (n / mid);
        }

        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size(), ans = 0;
        int left = 1, right = *max_element(candies.begin(), candies.end());

        while(left <= right) {
            int mid = (right - left)/2 + left;
            if(isValid(mid, candies, k)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};