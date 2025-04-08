class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        HashSet<Integer> st = new HashSet<>();

        for(int i = n - 1; i>=0; i--) {
            if(st.contains(nums[i])) return i / 3 + 1;
            st.add(nums[i]);
        }

        return 0;
    }
}