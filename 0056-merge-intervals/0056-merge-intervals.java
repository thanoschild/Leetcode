class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        List<int[]> merged = new ArrayList<>();
        int[] currentInterval = intervals[0];

        for(int i = 1; i<intervals.length; i++) {
            if(currentInterval[1] >= intervals[i][0]) {
                currentInterval[0] = Math.min(currentInterval[0], intervals[i][0]);
                currentInterval[1] = Math.max(currentInterval[1], intervals[i][1]);
            }
            else {
                merged.add(currentInterval);
                currentInterval = intervals[i];
            }
        }
        merged.add(currentInterval);

        int[][] ans = new int[merged.size()][2];
        for(int i = 0; i<merged.size(); i++) {
            ans[i] = merged.get(i);
        }

        return ans;
    }
}