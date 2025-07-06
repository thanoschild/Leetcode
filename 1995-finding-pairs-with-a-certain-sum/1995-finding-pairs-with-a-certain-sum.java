class FindSumPairs {
    int[] nums1, nums2;
    HashMap<Integer, Integer> mp = new HashMap<>();
    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        Arrays.sort(nums1);
        for(int it : nums2) mp.put(it, mp.getOrDefault(it, 0) + 1);
    }
    
    public void add(int index, int val) {
        mp.put(nums2[index], mp.getOrDefault(nums2[index], 0) - 1);
        nums2[index] += val;
        mp.put(nums2[index], mp.getOrDefault(nums2[index], 0) + 1);
    }
    
    public int count(int tot) {
        int ans = 0;
        for(int it : nums1) {
            if(it > tot) break;
            ans += mp.getOrDefault(tot - it, 0);
        }

        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */