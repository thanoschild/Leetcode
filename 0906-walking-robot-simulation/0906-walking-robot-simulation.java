class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        Set<String> st = new HashSet<>();
        for(int[] obs : obstacles) {
            st.add(obs[0] + " " + obs[1]);
        }

        int[][] dirs = new int[][] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, x = 0, y = 0, ans = 0;

        for(int c : commands) {
            if(c == -1) {
                d++;
                if(d == 4) d = 0;
            } else if(c == -2) {
                d--;
                if(d == -1) d = 3;
            }
            else {
                while(c-- > 0 && !st.contains((x + dirs[d][0]) + " " + (y + dirs[d][1]))) {
                    x += dirs[d][0];
                    y += dirs[d][1];
                }
            }
            ans = Math.max(ans, x*x + y*y);
        }

        return ans;
    }
}