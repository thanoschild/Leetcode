class Solution {
    public int differenceOfSums(int n, int m) {
        int totalSum = (n * (n + 1))/2;
        // Sn = (n/m) * (n/m + 1) * m / 2
        int divisibleSum = (n/m) * (n/m + 1) * m/2;
        return totalSum - 2 * divisibleSum;
    }
}