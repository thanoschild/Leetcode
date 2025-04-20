class Solution {
    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int it : answers) mp.put(it, mp.getOrDefault(it, 0) + 1);

        int ans = 0;
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            if(key > value) {
                ans += (key + 1);
            } else {
                if(value % (key + 1) == 0) ans += value;
                else {
                    int group = (value / (key + 1)) + 1;
                    ans += (group * (key + 1));
                }
            }
        }

        return ans;
    }
}