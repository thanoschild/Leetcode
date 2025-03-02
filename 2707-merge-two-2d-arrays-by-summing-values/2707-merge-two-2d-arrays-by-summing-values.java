class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n = nums1.length, m = nums2.length, i = 0, j = 0;
        List<int[]> result = new ArrayList<>();

        while(i < n && j < m) {
            int id1 = nums1[i][0], val1 = nums1[i][1];
            int id2 = nums2[j][0], val2 = nums2[j][1];
            
            if(id1 < id2) {
                result.add(new int[]{id1, val1});
                i++;
            } else if(id1 > id2) {
                result.add(new int[]{id2, val2});
                j++;
            } else {
                result.add(new int[]{id1, val1 + val2});
                i++;
                j++;
            }
        }

        while(i < n) {
            result.add(nums1[i]);
            i++;
        }

        while(j < m) {
            result.add(nums2[j]);
            j++;
        }

        int[][] ans = new int[result.size()][2];
        for(int k = 0; k<result.size(); k++) {
            ans[k] = result.get(k);
        }

        return ans;
    }
}