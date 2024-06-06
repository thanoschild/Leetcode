class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;
        if(n % groupSize != 0) return false;
        Map<Integer, Integer> mp = new TreeMap<>();
        for(int x : hand) mp.put(x, mp.getOrDefault(x, 0) + 1);

        for(int it : mp.keySet()) {
            if(mp.get(it) > 0) {
                for(int i = groupSize-1; i>=0; i--) {
                    if(mp.getOrDefault(it + i, 0) < mp.get(it)) return false;
                    mp.put(it+i, mp.get(it+i) - mp.get(it));
                }
            }
        }

        return true;
    }
}