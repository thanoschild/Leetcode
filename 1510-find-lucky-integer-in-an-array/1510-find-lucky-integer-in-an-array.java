class Solution {
    public int findLucky(int[] arr) {
        int ans = -1;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int it : arr) {
            mp.put(it, mp.getOrDefault(it, 0) + 1);
        }

        for(int key : mp.keySet()) {
            if(key == mp.get(key)) {
                ans = Math.max(ans, key);
            }
        }

        return ans;
    }
}