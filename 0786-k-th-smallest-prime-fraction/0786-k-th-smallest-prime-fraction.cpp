class Solution {
public:
    vector<int> findCounts(vector<int> &arr, double mid) {
        int j = 1, total = 0, num = 0, den = 0, n = arr.size();
        double frac = 0.0;

        for(int i = 0; i<n; i++) {
            while(j < n && arr[i] >= arr[j] * mid) j++;
            total += n - j;

            if(j < n && frac < arr[i] * 1.0/arr[j]) {
                frac = arr[i] * 1.0/arr[j];
                num = i, den = j;
            }
        }
        return {total, num, den};
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1;
        vector<int> ans;

        while(left <= right) {
            double mid = (right - left)/2 + left;
            vector<int> pos = findCounts(arr, mid);
            if(pos[0] == k) {
                ans = {arr[pos[1]], arr[pos[2]]};
                break;
            }

            if(pos[0] > k) right = mid;
            else left = mid;
        }

        return ans;
    }
};