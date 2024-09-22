class Solution {
    private long countSteps(long curr, long n) {
        long steps = 0, first = curr, last = curr;
        while(first <= n) {
            steps += Math.min(n+1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }

    public int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while(k > 0) {
            long steps = countSteps(curr, n);
            if(steps <= k) {
                k -= steps;
                curr++;
            }
            else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
}