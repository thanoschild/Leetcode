class Solution {
    private boolean isValid(int mid, int[] candies, long k) {
        long count = 0;
        for(int c : candies) {
            count += (c / mid);
        }

        return count >= k;
    }

    public int maximumCandies(int[] candies, long k) {
        int ans = 0, left = 1, right = candies[0];
        for(int c : candies) right = Math.max(right, c);

        while(left <= right) {
            int mid = (right - left)/2 + left;
            if(isValid(mid, candies, k)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
}