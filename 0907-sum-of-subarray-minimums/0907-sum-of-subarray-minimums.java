class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        Stack<Integer> st1 = new Stack<>();
        Stack<Integer> st2 = new Stack<>();
        int[] next = new int[n];
        int[] prev = new int[n];
        final int mod = (int) 1e9 + 7;
        long ans = 0;

        for(int i = 0; i<n; i++) {
            next[i] = n - i - 1;
            prev[i] = i;
        }

        for (int i = 0; i < n; i++) {
            while (!st1.isEmpty() && arr[st1.peek()] > arr[i]) {
                next[st1.peek()] = i - st1.peek() - 1;
                st1.pop();
            }
            st1.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st2.isEmpty() && arr[st2.peek()] >= arr[i]) {
                prev[st2.peek()] = st2.peek() - i - 1;
                st2.pop();
            }
            st2.push(i);
        }

        for(int i = 0; i<n; i++) {
            long pro = ((next[i] + 1) * (prev[i] + 1)) % mod;
            pro = (arr[i] * pro) % mod;
            ans = (ans + pro) % mod;
        }

        return (int) ans;
    }
}