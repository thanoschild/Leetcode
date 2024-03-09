class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length, i = 0, j = 0;

        while(i < n && j < m) {
            if(nums1[i] > nums2[j]) j++;
            else if(nums1[i] < nums2[j]) i++;
            else return nums1[i];
        }

        return -1;
    }
}