class Solution {
    public int maximumSum(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int ans = -1;

        for(int n : nums) {
            int sum = 0, curr = n;

            while(curr > 0) {
                sum += curr % 10;
                curr = curr / 10;
            }

            if(mp.containsKey(sum)) {
                ans = Math.max(ans, mp.get(sum) + n);
                if(mp.get(sum) < n) mp.put(sum, n);
            } else {
                mp.put(sum, n);
            }
        }

        return ans;
    }
}