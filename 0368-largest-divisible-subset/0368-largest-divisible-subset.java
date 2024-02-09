class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        if(n == 1) {
            List<Integer> result = new ArrayList<>();
            result.add(nums[0]);
            return result;
        }
        int[] dp = new int[n];
        int[] parent = new int[n];
        for(int i = 0; i<n; i++) dp[i] = 1;

        int source = 0, mx = 1;
        Arrays.sort(nums);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > mx) {
                mx = dp[i];
                source = i;
            }
        }

        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i<mx; i++) {
            ans.add(nums[source]);
            source = parent[source];
        }

        return ans;
    }
}