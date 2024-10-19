class Solution {
    private void solve(int n, StringBuilder s) {
        if(n == 0) return;

        StringBuilder newS = new StringBuilder(s);
        int mid = newS.length()/2;
        if (newS.charAt(mid) == '0') newS.setCharAt(mid, '1');
        else newS.setCharAt(mid, '0');

        s.append('1');
        s.append(newS);
        solve(n - 1, s);
    }
    
    public char findKthBit(int n, int k) {
        StringBuilder s = new StringBuilder("0");
        solve(n-1, s);
        return s.charAt(k - 1);
    }
}