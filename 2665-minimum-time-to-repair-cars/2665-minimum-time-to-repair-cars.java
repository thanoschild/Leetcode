class Solution {
    private boolean isValid(long time, int[] ranks, int cars) {
        long count = 0;
        for(int rank : ranks) {
            count += (long) Math.sqrt(time / rank);
            if(count >= cars) return true;
        }

        return count >= cars;
    }

    public long repairCars(int[] ranks, int cars) {
        long left = 1, right = (long)1e14, ans = 0;

        while(left <= right) {
            long mid = (right - left)/2 + left;
            if(isValid(mid, ranks, cars)) {
               right = mid - 1;
               ans = mid;
            } else {
               left = mid + 1;
            }
        }

        return ans;
    }
}