class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int ans = 0;

        while(start < end) {
            int h1 = height[start];
            int h2 = height[end];
            int minHeight = min(h1, h2);
            ans = max(ans, minHeight * (end - start));
            if(h1 > h2) end--;
            else start++;
        }

        return ans;
    }
};