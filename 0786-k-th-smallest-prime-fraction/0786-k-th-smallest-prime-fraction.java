class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                int x = arr[a[0]]*arr[b[1]];
                int y = arr[b[0]]*arr[a[1]];
                return x - y;
            }
        });

        for(int i = 0; i<n-1; i++) {
            pq.add(new int[] {i, n-1});
        }

        while(k > 1) {
            int[] t = pq.remove();
            if(t[1] - 1 > t[0]) {
               t[1]--;
               pq.add(t);
            }
            k--;
        }

        int[] t = pq.peek();
        return new int[] {arr[t[0]], arr[t[1]]};
    }
}