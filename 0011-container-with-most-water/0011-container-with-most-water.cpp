class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()- 1, ans = 0;

        while(l <= r) {
            int len = r - l;
            int hei = min(height[l], height[r]);
            ans = max(ans, len * hei);
            if(height[l] > height[r]) r--;
            else l++;
        }

        return ans;
    }
};