class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1, ans = 0;

        while(l <= r) {
            int len = r - l;
            int hei = Math.min(height[l], height[r]);
            ans = Math.max(ans, len * hei);
            if(height[l] > height[r]) r--;
            else l++;
        }

        return ans;
    }
}