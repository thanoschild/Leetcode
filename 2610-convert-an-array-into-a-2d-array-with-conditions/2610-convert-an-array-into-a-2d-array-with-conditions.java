class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        int maxFreq = 0;
        int n = nums.length;
        int[] freq = new int[n+1];

        for(int x : nums) {
            freq[x]++;
            maxFreq = Math.max(maxFreq, freq[x]);
        }

        List<List<Integer>> ans = new ArrayList<>(maxFreq);
        for (int i = 0; i < maxFreq; i++) {
            ans.add(new ArrayList<>());
        }

        for(int i = 0; i<freq.length; i++) {
            for(int j = 0; j<freq[i]; j++) {
                ans.get(j).add(i);
            }
        }

        return ans;
    }
}