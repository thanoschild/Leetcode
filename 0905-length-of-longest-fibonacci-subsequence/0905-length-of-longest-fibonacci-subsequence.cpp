class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int ans = 0, count = 0, n = arr.size();

        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                int a = arr[i], b = arr[j];
                int c = a + b;
                count = 2;

                while(st.find(c) != st.end()) {
                    count++;
                    a = b;
                    b = c;
                    c = a + b;
                }

                ans = max(ans, count);
            }
        }

        return ans > 2 ? ans : 0;
    }
};