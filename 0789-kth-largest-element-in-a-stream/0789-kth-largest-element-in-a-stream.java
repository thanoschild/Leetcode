class KthLargest {
    PriorityQueue<Integer> pq;
    int limit;
    public KthLargest(int k, int[] nums) {
        limit = k;
        pq = new PriorityQueue<>();
        for(int n : nums) pq.add(n);
    }
    
    public int add(int val) {
        pq.add(val);
        while(pq.size() > limit) pq.poll();
        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */