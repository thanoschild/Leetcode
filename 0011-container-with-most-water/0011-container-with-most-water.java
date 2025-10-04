class Solution {
    public int maxArea(int[] height) {
        int start = 0, end = height.length - 1;
        int ans = 0;

        while(start < end) {
            int minHeight = Math.min(height[start], height[end]);
            int len = end - start;
            ans = Math.max(ans, len * minHeight);
            if(height[start] > height[end]) end--;
            else start++;
        }

        return ans;
    }
}