class Solution {
    private int findSum(int n) {
        return n * (n + 1)/2;
    }
    
    public int pivotInteger(int n) {
        int left = 1, right = n;
        while(left <= right) {
            int mid = (right - left)/2 + left;
            int x = findSum(mid);
            int y = findSum(n) - x + mid;
            if(x == y) return mid;
            if(x > y) right = mid - 1;
            else left = mid + 1;
        }

        return -1;
    }
}