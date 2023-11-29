class Solution {
    public int numberOfWays(String cor) {
        int seats = 0, n = cor.length(), mod = (int) 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (cor.charAt(i) == 'S') {
                seats++;
            }
        }

        if (seats == 0 || seats % 2 != 0) {
            return 0;
        }

        long ans = 1, count = 0, plant = 0;
        for (int i = 0; i < n; i++) {
            if (cor.charAt(i) == 'S') {
                count++;
            }
            if (count == 2) {
                i++;
                plant = 1;
                while (i < n && cor.charAt(i) == 'P') {
                    plant++;
                    i++;
                }
                if (i == n) {
                    break;
                }
                ans = (ans * plant) % mod;
                count = 0;
                i--;
            }
        }

        return (int) ans;
    }
}