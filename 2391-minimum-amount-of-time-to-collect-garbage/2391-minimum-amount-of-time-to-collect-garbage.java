class Solution {
    private static int countOccurrences(String str, char target) {
        int count = 0;
        for (char c : str.toCharArray()) {
            if (c == target) {
                count++;
            }
        }
        return count;
    }
    
    public int garbageCollection(String[] garbage, int[] travel) {
        int ans = 0;
        char[] c = {'G', 'M', 'P'};
        
        for (char x : c) {
            int time = 0, lastpick = 0;

            for (int i = 0; i < garbage.length; i++) {
                int cnt = countOccurrences(garbage[i], x);
                if (cnt > 0) {
                    time += cnt;
                    lastpick = i;
                }
                if (i < travel.length) {
                    time += travel[i];
                }
            }

            for (int j = garbage.length - 2; j >= lastpick; j--) {
                time -= travel[j];
            }

            ans += time;
        }

        return ans;
    }
}