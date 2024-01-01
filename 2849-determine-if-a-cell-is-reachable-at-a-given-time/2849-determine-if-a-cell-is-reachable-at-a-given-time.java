class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffX = Math.abs(sx - fx);
        int diffY = Math.abs(sy - fy);

        if(diffX == 0 && diffY == 0) {
            return t != 1;
        }

        return diffX <= t && diffY <= t;
    }
}