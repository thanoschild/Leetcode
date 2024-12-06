class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        HashSet<Integer> st = new HashSet<>();
        for(int num : banned) st.add(num);

        long sum = 0;
        int count = 0;

        for(int i = 1; i<=n; i++) {
            if(!st.contains(i)) {
                sum += i;
                if(sum > maxSum) break;
                count++;
            }
        }

        return count;
    }
}