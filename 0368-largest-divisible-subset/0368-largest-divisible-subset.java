class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        if(n == 1) return Arrays.asList(nums[0]);
        
        int start = -1, maxVal = -1;
        Arrays.sort(nums);
        int[] dp = new int[n];
        int[] parent = new int[n];
        Arrays.fill(dp, 1);

        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if(dp[i] > maxVal) {
                maxVal = dp[i];
                start = i;
            }
        }

        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i<maxVal; i++) {
            ans.add(nums[start]);
            start = parent[start];
        }

        return ans;
    }
}