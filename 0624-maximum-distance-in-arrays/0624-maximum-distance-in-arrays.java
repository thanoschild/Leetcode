class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int mx = arrays.get(0).get(arrays.get(0).size() - 1);  
        int mn = arrays.get(0).get(0);  
        int diff = 0;

        for (int i = 1; i < arrays.size(); i++) {
            List<Integer> it = arrays.get(i);
            int currMax = it.get(it.size() - 1);
            int currMin = it.get(0);

            diff = Math.max(diff, Math.abs(mx - currMin));
            diff = Math.max(diff, Math.abs(currMax - mn));

            mx = Math.max(mx, currMax);
            mn = Math.min(mn, currMin);
        }

        return diff;
    }
}