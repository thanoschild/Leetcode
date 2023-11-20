class Solution {
    public int reductionOperations(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        
        int count = 0, prev = 0;
        for(int i = 1; i<n; i++) {
            if(nums[i] == nums[i-1]) {
                if(prev == 0) continue;
                else {
                    count += prev;
                }
            }
            else{
                prev += 1;
                count += prev;
            }
        }
        
        return count;
    }
}