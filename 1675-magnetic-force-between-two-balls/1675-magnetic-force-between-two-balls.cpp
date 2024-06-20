class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), left = 0, right = position[n-1];
        int ans = 0;

        while(left <= right) {
            int mid = (right - left)/2 + left;
            int curr = 0, count = 1;
            for(int i = 0; i<n; i++) {
                if(position[i] - position[curr] >= mid) {
                    count++;
                    curr = i;
                }
            }

            if(count >= m) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};