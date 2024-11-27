class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<List<Integer>> edges = new ArrayList<>();
        for(int i = 0; i<n; i++) {
            edges.add(new ArrayList<>());
            edges.get(i).add(i+1);
        }

        Function<Void, Integer> shortestPath = __ -> {
            Queue<int[]> pq = new LinkedList<>();
            pq.offer(new int[] {0, 0});
            Set<Integer> visited = new HashSet<>();
            visited.add(0);

            while(!pq.isEmpty()) {
                int[] curr = pq.poll();
                int currNode = curr[0];
                int len = curr[1];

                if(currNode == n - 1) return len;

                for(int node : edges.get(currNode)) {
                    if(!visited.contains(node)) {
                        pq.offer(new int[]{node, len+1});
                        visited.add(node);
                    }
                }
            }

            return -1;
        };

        int[] ans = new int[queries.length];
        for(int i = 0; i<queries.length; i++) {
            edges.get(queries[i][0]).add(queries[i][1]);
            ans[i] = shortestPath.apply(null); 
        }

        return ans;
    }
}