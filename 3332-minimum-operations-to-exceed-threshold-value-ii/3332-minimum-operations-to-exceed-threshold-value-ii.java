class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ops = 0;

        for(int n : nums) {
            if(n < k) pq.add(n);
        }

        while(!pq.isEmpty()) {
            int x = pq.poll();
            ops++;

            if(pq.isEmpty()) break;
            int y = pq.poll();

            long val = 2L * x + y;
            if(val < k) pq.add((int)val);
        }

        return ops;
    }
}