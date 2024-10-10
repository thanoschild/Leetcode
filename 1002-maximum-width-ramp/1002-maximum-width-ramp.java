class Solution {
    public int maxWidthRamp(int[] nums) {
        List<Integer> s = new ArrayList<>();
        int res = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (s.size() == 0 || nums[i] < nums[s.get(s.size() - 1)]) {
                s.add(i);
            } else {
                int left = 0, right = s.size() - 1, mid = 0;
                while (left < right) {
                    mid = (left + right) / 2;
                    if (nums[s.get(mid)] > nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                res = Math.max(res, i - s.get(left));
            }
        }
        return res;
    }
}