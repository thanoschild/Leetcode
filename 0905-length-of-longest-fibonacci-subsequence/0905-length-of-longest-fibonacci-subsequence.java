class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        HashSet<Integer> st = new HashSet<>();
        for(int it : arr) st.add(it);

        int ans = 0, count = 0, n = arr.length;
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                int a = arr[i], b = arr[j];
                int c = a + b;
                count = 2;

                while(st.contains(c)) {
                    count++;
                    a = b;
                    b = c;
                    c = a + b;
                }

                ans = Math.max(ans, count);
            }
        }

        return ans > 2 ? ans : 0;
    }
}