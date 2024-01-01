class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff_x = abs(sx - fx);
        int diff_y = abs(sy - fy);

        if(diff_x == 0 && diff_y == 0) {
            return t != 1;
        }

        return diff_x <= t && diff_y <= t;
    }
};