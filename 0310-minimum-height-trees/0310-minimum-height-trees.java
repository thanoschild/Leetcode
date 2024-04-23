class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> ans = new ArrayList<>();
        if (n == 0) return ans;
        else if (n == 1) {
            ans.add(0);
            return ans;
        }

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] indegree = new int[n];

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        Queue<Integer> pq = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) pq.offer(i);
        }

        while (!pq.isEmpty()) {
            ans.clear();
            int size = pq.size();
            for (int i = 0; i < size; i++) {
                int curr = pq.poll();
                ans.add(curr);

                for (int neighbor : adj.get(curr)) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 1) {
                        pq.offer(neighbor);
                    }
                }
            }
        }

        return ans;
    }
}