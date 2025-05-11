class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        for(int it : nums1) {
            s1 += it;
            if(it == 0) c1++;
        }

        for(int it : nums2) {
            s2 += it;
            if(it == 0) c2++;
        }

        if(c1 == 0 && s1 < s2 + c2) return -1;
        if(c2 == 0 && s2 < s1 + c1) return -1;
        return Math.max(c1 + s1, s2 + c2);
    }
}