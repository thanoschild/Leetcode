class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> res = new ArrayList<>();
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int it : nums1) {
            mp.put(it, mp.getOrDefault(it, 0) + 1);
        }
        for(int it : nums2) {
            if(mp.getOrDefault(it, 0) > 0) {
                res.add(it);
                mp.put(it, mp.getOrDefault(it, 0) - 1);
            }
        }

        int n = res.size();
        int[] ans = new int[n];
        for(int i = 0; i<n; i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }
}