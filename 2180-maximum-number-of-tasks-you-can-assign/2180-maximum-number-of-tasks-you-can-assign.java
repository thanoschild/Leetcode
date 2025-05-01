class Solution {
    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        int n = tasks.length, m = workers.length;
        Arrays.sort(tasks);
        Arrays.sort(workers);

        int lo = 0, hi = Math.min(n, m);
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int count = 0;
            boolean flag = true;
            TreeMap<Integer, Integer> mp = new TreeMap<>();
            for(int w : workers) mp.put(w, mp.getOrDefault(w, 0) + 1);

            for(int i = mid - 1; i>=0; i--) {
                int currWorker = mp.lastKey();
                if(tasks[i] <= currWorker) {
                    mp.put(currWorker, mp.get(currWorker) - 1);
                    mp.remove(currWorker, 0);
                } else {
                    Integer currWorker2 = mp.ceilingKey(tasks[i] - strength);
                    if(currWorker2 != null) {
                        count++;
                        mp.put(currWorker2, mp.get(currWorker2) - 1);
                        mp.remove(currWorker2, 0);
                    } else {
                        flag = false;
                        break;
                    }
                } 

                if(count > pills) {
                    flag = false;
                    break;
                }
            }

            if(flag) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
}