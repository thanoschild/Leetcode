class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int n : target) {
            mp.put(n, mp.getOrDefault(n, 0) + 1);
        }
        for(int n : arr) {
            mp.put(n, mp.getOrDefault(n, 0) - 1);
            if(mp.get(n) < 0) return false;
        }

        return true;
    }
}