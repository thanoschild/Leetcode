class Solution {
    public int minOperations(int[] nums, int k) {
        HashSet<Integer> st = new HashSet<>();
        for(int n : nums) {
            if(n < k) return -1;
            else if(n > k) st.add(n);
        }

        return st.size();
    }
}