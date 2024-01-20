class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st1, st2;
        vector<int> next(n), prev(n);
        long long ans = 0, mod = 1e9 + 7;

        for(int i = 0; i<n; i++) {
            next[i] = n - i - 1;
            prev[i] = i;
        }

        for(int i = 0; i<n; i++) {
            while(!st1.empty() && arr[st1.top()] > arr[i]) {
                next[st1.top()] = i - st1.top() - 1;
                st1.pop();
            }
            st1.push(i);
        }

        
        for(int i = n - 1; i>=0; i--) {
            while(!st2.empty() && arr[st2.top()] >= arr[i]) {
                prev[st2.top()] = st2.top() - i - 1;
                st2.pop();
            }
            st2.push(i);
        }

        for(int i = 0; i<n; i++) {
            long long pro = ((next[i] + 1) * (prev[i] + 1)) % mod;
            pro = (arr[i]*pro) % mod;
            ans = (ans + pro) % mod;
        }

        return (int) ans;
    }
};