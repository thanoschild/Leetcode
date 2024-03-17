class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int n = intervals.length, idx = 0;

        while(idx < n && intervals[idx][1] < newInterval[0]) {
            ans.add(intervals[idx]);
            idx++;
        }

        while(idx < n && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[idx][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[idx][1]);
            idx++;
        }

        ans.add(newInterval);
        while(idx < n) {
            ans.add(intervals[idx]);
            idx++;
        }

        int m = ans.size();
        int[][] result = new int[m][2];
        for(int i = 0; i<m; i++) {
            result[i] = ans.get(i);
        }

        return result;
    }
}