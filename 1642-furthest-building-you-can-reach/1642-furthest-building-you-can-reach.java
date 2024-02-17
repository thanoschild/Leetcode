class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        int n = heights.length, i = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(i = 0; i<n-1; i++) {
            int diff = heights[i+1] - heights[i];
            if(diff < 0) continue;
            else if(diff <= bricks) {
                bricks -= diff;
                pq.add(diff);
            }
            else if(ladders > 0) {
                if(!pq.isEmpty() && pq.peek() > diff) {
                    bricks += pq.poll();
                    bricks -= diff;
                    pq.add(diff);
                }
                ladders--;
            }
            else break;
        }

        return i;
    }
}