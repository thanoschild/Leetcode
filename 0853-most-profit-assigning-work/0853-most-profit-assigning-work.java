class Solution {
    private static class JobComparator implements Comparator<int[]> {
        @Override
        public int compare(int[] a, int[] b) {
            if (a[0] == b[0]) {
                return Integer.compare(b[1], a[1]); 
            }
            return Integer.compare(a[0], b[0]); 
        }
    }

    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = profit.length;
        List<int[]> jobs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            jobs.add(new int[]{difficulty[i], profit[i]});
        }

        jobs.sort(new JobComparator());
        Arrays.sort(worker);

        int ans = 0, idx = 0, curr = 0, m = worker.length;
        for (int i = 0; i < m; i++) {
            while (idx < n && jobs.get(idx)[0] <= worker[i]) {
                curr = Math.max(curr, jobs.get(idx)[1]);
                idx++;
            }
            ans += curr;
        }

        return ans;
    }
}