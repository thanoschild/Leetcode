class Solution {
    public int trap(int[] height) {
        int n = height.length;
        Stack<Integer> st = new Stack<>();
        int ans = 0;

        for(int i = 0; i<n; i++) {
            while(!st.isEmpty() && height[st.peek()] < height[i]) {
                int t = st.pop();
                if(st.isEmpty()) break;
                int h = Math.min(height[i], height[st.peek()]) - height[t];
                int l = i - st.peek() - 1;
                ans += (l*h);
            }
            st.add(i);
        }

        return ans;
    }
}