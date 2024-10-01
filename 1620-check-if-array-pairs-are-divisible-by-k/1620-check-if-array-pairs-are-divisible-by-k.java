class Solution {
    public boolean canArrange(int[] arr, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int it : arr) {
            int rem = (it % k + k) % k;
            mp.put(rem, mp.getOrDefault(rem, 0) + 1);
        }

        for(int i = 1; i<=k/2; i++) {
            int a = mp.getOrDefault(i, 0);
            int b = mp.getOrDefault(k - i, 0);
            if(a != b) return false;
        }

        return mp.getOrDefault(0, 0) % 2 == 0;
    }
}