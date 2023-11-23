class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int n = l.length;
        List<Boolean> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            List<Integer> subarray = new ArrayList<>();
            for (int j = l[i]; j <= r[i]; j++) {
                subarray.add(nums[j]);
            }
            Collections.sort(subarray);
            boolean flag = true;

            if (subarray.size() > 1) {
                int diff = subarray.get(1) - subarray.get(0);
                for (int k = 1; k < subarray.size() - 1; k++) {
                    if (subarray.get(k + 1) - subarray.get(k) != diff) {
                        flag = false;
                        break;
                    }
                }
            } else {
                flag = false;
            }
            ans.add(flag);
        }

        return ans;
    }
}