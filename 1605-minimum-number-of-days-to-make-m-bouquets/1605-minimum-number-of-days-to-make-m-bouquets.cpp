class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int left = 0, right = 1e9, ans = -1;

        while(left <= right) {
            int mid = (right - left)/2 + left;
            int con = 0, buk = 0;

            for(int i = 0; i<n; i++) {
                if(bloomDay[i] <= mid) {
                   con++;
                   if(con >= k) {
                       con = 0;
                       buk++;
                   }
                }
                else {
                    con = 0;
                }
            }

            if(buk >= m) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};