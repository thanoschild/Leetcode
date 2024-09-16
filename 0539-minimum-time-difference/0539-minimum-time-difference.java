class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] seen = new boolean[24 * 60];
        int maxMin = Integer.MIN_VALUE, minMin = Integer.MAX_VALUE;
        for(String s : timePoints) {
            String[] t = s.split(":");
            int h = Integer.parseInt(t[0]);
            int m = Integer.parseInt(t[1]);
            
            if(seen[h*60 + m]) return 0;

            maxMin = Math.max(maxMin, h * 60 + m);
            minMin = Math.min(minMin, h * 60 + m);
            seen[h*60 + m] = true;
        }

        int diff = Integer.MAX_VALUE, prev = 0;
        for(int i = minMin; i<=maxMin; i++) {
            if(seen[i]) {
                if(i == minMin) {
                    diff = Math.min(diff, Math.min(maxMin - minMin, 1440 - maxMin + minMin));
                }
                else {
                    diff = Math.min(diff, i - prev);
                }
                prev = i;
            }
        }

        return diff;
    }
}