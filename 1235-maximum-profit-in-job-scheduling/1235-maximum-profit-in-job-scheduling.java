class Solution {
  
    Comparator<int[]> myComparator = new Comparator<int[]>() {
        public int compare(int[] a, int[] b) {
            if (a[1] == b[1] && a[0] > b[0]) return 1;
            else if(a[1] > b[1]) return 1;
            return -1;
        }
    };

    public int jobScheduling(int[] start, int[] end, int[] pro) {
        int n = start.length;
        List<int[]> jobs = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            jobs.add(new int[]{start[i], end[i], pro[i]});
        }
        Collections.sort(jobs, myComparator);

        TreeMap<Integer, Integer> mp = new TreeMap<>();
        mp.put(0, 0);

        for (int[] it : jobs) {
            int curr = mp.floorEntry(it[0]).getValue() + it[2];
            if (curr > mp.lastEntry().getValue()) {
                mp.put(it[1], curr);
            }
        }

        return mp.lastEntry().getValue();
    }
}