class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> st = new Stack<>();
        int ans = 0;

        for(int i = 0; i<=n; i++) {
            int curr = i == n ? 0 : heights[i];
            while(!st.isEmpty() && heights[st.peek()] > curr) {
                int h = heights[st.pop()];
                if(st.isEmpty()) {
                    ans = Math.max(ans, i * h);
                }
                else {
                    int l = i - st.peek() - 1;
                    ans = Math.max(ans, l * h);
                }
            }
            st.add(i);
        }

        return ans;
    }
}
