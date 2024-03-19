class Solution {
    public int leastInterval(char[] tasks, int n) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int maxCount = 0;
        for(char c : tasks) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
            maxCount = Math.max(maxCount, mp.get(c));
        }

        int ans = (maxCount - 1) * (n + 1);
        for(int x : mp.values()) {
            if(x == maxCount) ans++;
        }

        return Math.max(ans, tasks.length);
    }
}