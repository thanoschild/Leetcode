class Solution {
    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int[] it : intervals) {
            if(!pq.isEmpty() && pq.peek() < it[0]) {
                pq.poll();
            }
            pq.add(it[1]);
        }

        return pq.size();
    }
}