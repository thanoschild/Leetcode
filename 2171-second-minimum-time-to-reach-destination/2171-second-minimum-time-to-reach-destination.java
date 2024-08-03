class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        List<List<Integer>> adj = new ArrayList<>(n+1);
        for(int i = 0; i<=n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] it : edges) {
            adj.get(it[0]).add(it[1]);
            adj.get(it[1]).add(it[0]);
        }

        Queue<int[]> pq = new LinkedList<>();
        pq.add(new int[]{1, 0});
        int[] visitedTime = new int[n+1];
        int[] visited = new int[n+1];
        int firstVisited = Integer.MAX_VALUE;

        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int node = curr[0], t = curr[1];
            for(int next : adj.get(node)) {
                int t2 = t;
                int isReg = (t2 / change) % 2;
                if(isReg == 1) t2 += change - (t2 % change);
                t2 += time;

                if(next == n && firstVisited == Integer.MAX_VALUE) firstVisited = t2;
                if(next == n && firstVisited < t2) return t2;
                if(visitedTime[next] != t2 && visited[next] <= 1) {
                    visited[next]++;
                    visitedTime[next] = t2;
                    pq.add(new int[]{next, t2});
                }
            }
        }

        return -1;
    }
}