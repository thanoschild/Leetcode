class Pair {
    int node;
    double probability;

    Pair(int node, double probability) {
        this.node = node;
        this.probability = probability;
    }
}

class Solution {
    public double maxProbability(int n, int[][] edges, double[] prob, int start, int end) {
        List<List<Pair>> adj = new ArrayList<>(n);
        for(int i = 0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i<edges.length; i++) {
            adj.get(edges[i][0]).add(new Pair(edges[i][1], prob[i]));
            adj.get(edges[i][1]).add(new Pair(edges[i][0], prob[i]));
        }

        double[] maxProb = new double[n];
        boolean[] seen = new boolean[n];
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Double.compare(b.probability, a.probability));
        pq.add(new Pair(start, 1.0));
        maxProb[start] = 1.0;

        while(!pq.isEmpty()) {
            Pair top = pq.poll();
            int node = top.node;
            double probability = top.probability;

            if(!seen[node]) {
                seen[node] = true;
                for(Pair to : adj.get(node)) {
                    if(maxProb[to.node] < probability * to.probability) {
                        maxProb[to.node] = to.probability * probability;
                        pq.add(new Pair(to.node, maxProb[to.node]));
                    }
                }
            }
        }

        return maxProb[end];
    }
}