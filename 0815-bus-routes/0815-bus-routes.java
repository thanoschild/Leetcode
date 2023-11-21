class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        int n = routes.length;
        Map<Integer, List<Integer>> mp = new HashMap<>();

        for(int i = 0; i<n; i++) {
            for(int j : routes[i]) {
                mp.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
            }
        }

        Queue<Integer> pq = new LinkedList<>();
        pq.add(source);

        Map<Integer, Integer> busStop = new HashMap<>();
        Map<Integer, Integer> bus = new HashMap<>();
        busStop.put(source, 1);
        int buses = 0;

        while(!pq.isEmpty()) {
            int k = pq.size();

            while(k-- > 0) {
                int t = pq.poll();

                if(t == target) return buses;

                for(int it : mp.getOrDefault(t, new ArrayList<>())) {
                    if(bus.get(it) == null) {
                        bus.put(it, 1);

                        for(int x : routes[it]) {
                            if(busStop.get(x) == null) {
                                busStop.put(x, 1);
                                pq.add(x);
                            }
                        }
                    }
                }
            }
            buses++;
        }

        return -1;
    }
}