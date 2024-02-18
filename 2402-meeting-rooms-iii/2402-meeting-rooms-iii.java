class Solution {
    public int mostBooked(int n, int[][] meet) {
         int[] ans = new int[n];
         long[] time = new long[n];
         Arrays.sort(meet, (a, b) -> a[0] - b[0]);

         for(int i = 0; i<meet.length; i++) {
            int start = meet[i][0], end = meet[i][1];
            long minval = (long) 1e18;
            int idx = -1;
            boolean flag = true;

            for(int j = 0; j<n; j++) {
                if(minval > time[j]) {
                    minval = time[j];
                    idx = j;
                }

                if(start >= time[j]) {
                    time[j] = end;
                    ans[j]++;
                    flag = false;
                    break;
                }
            }

            if(flag) {
                ans[idx]++;
                time[idx] += (end - start);
            } 
         }

         int idx = -1, count = -1;
         for(int i = 0; i<n; i++) {
             if(ans[i] > count) {
                 count = ans[i];
                 idx = i;
             }
         }

         return idx;
    }
}