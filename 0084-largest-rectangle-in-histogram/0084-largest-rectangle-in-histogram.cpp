class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int ans = 0;
        stack<int> st;

        for(int i = 0; i<n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                if(st.empty()) {
                    ans = max(ans, h*i);
                }
                else {
                    int l = i - st.top() - 1;
                    ans = max(ans, h * l);
                }
            }
            st.push(i);
        }

        return ans;
    }
};