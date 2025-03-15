class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);

        for(int i = 0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = n - 1;
       
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else {
                    ans.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(k > j && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }

        return ans;
    }
}