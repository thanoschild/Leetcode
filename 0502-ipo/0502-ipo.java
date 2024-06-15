class Solution {
    class Pair implements Comparable<Pair> {
        int capital, profit;
        
        public Pair(int capital, int profit) {
            this.capital = capital;
            this.profit = profit;
        }

        public int compareTo(Pair pair) {
            return capital - pair.capital;
        }
    }

    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        Pair[] projects = new Pair[n];
        for(int i = 0; i<n; i++) {
            projects[i] = new Pair(capital[i], profits[i]);
        }
        Arrays.sort(projects);

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int idx = 0;

        for(int i = 0; i<k; i++) {
            while(idx < n && projects[idx].capital <= w) {
                pq.add(projects[idx].profit);
                idx++;
            }

            if(!pq.isEmpty()) w += pq.poll();
        }

        return w;
    }
}