class Solution {
    public int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }

        int[] p = new int[31];
        p[0] = 1;
        int count = 1;

        for (int i = 1; i < 31; i++) {
            count *= 2;
            p[i] = p[i - 1] + count;
        }

        int bits = 32 - Integer.numberOfLeadingZeros(n);
        long ans = 0;
        boolean add = true;

        for (int i = bits - 1; i >= 0; i--) {
            if ((n & (1 << i)) != 0) {
                if (add) {
                    ans += p[i];
                    add = false;
                } else {
                    ans -= p[i];
                    add = true;
                }
            }
        }

        return (int) ans;
    }
}