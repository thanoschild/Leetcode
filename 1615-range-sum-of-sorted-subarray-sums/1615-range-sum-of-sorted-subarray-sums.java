class Pair {
    int sum;
    int idx;

    public Pair(int sum, int idx) {
        this.sum = sum;
        this.idx = idx;
    }
}


class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return Integer.compare(p1.sum, p2.sum);
            }
        });

        for(int i = 0; i<n; i++) {
            pq.add(new Pair(nums[i], i+1));
        }

        int ans = 0, mod = (int) 1e9 + 7;
        for(int i = 1; i<=right; i++) {
            Pair t = pq.poll();
            if(i >= left) {
                ans = (ans + t.sum) % mod;
            }
            if(t.idx < n) {
                int newSum = t.sum + nums[t.idx];
                pq.add(new Pair(newSum, t.idx + 1));
            }
        }

        return ans;
    }
}