class Solution {
    final long mod = (long) 1e9 + 7;
    private long binaryExpo(long a, long b) {
        long ans = 1;
        while(b > 0) {
            if((b & 1) >= 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }

        return ans;
    }

    public int countGoodNumbers(long n) {
        return (int)((binaryExpo(4, n / 2) * binaryExpo(5, n - n / 2)) % mod);
    }
}