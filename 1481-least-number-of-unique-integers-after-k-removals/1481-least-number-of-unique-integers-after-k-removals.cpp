class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int it : arr) {
            mp.put(it, mp.getOrDefault(it, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(mp.values());
        while(k > 0) {
            k -= pq.poll();
        }

        return k < 0 ? pq.size() + 1 : pq.size();
    }
}