class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0;
        for(int gift : gifts) {
            sum += gift;
            pq.add(-1*gift);
        }

        for(int i = 0; i<k; i++) {
           int t = pq.poll();
           int val = -1*t;
           if(val <= 1) break;
           int sq = (int)Math.sqrt(val);
           sum -= (val - sq);
           pq.add(-1 * sq);
        }

        return sum;
    }
}