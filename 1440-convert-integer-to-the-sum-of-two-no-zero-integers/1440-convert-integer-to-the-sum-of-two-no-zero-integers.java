class Solution {
    private boolean valid(int n) {
        String s = "";
        s += n;
        
        for(char c : s.toCharArray()) {
            if(c == '0') return false;
        }

        return true;
    }

    public int[] getNoZeroIntegers(int n) {
        int[] ans = new int[2];
        if(n < 2) return ans;

        for(int i = 1; i<=n/2; i++) {
            if(valid(i) && valid(n - i)) {
                ans[0] = i;
                ans[1] = n - i;
            }
        }

        return ans;
    }
}