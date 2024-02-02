class Solution {
    public void solve(int low, int high, int i, int num, List<Integer> ans) {
        if(num >= low && num <= high) ans.add(num);
        if(num > high || i > 9) return;
        solve(low, high, i+1, num*10 + i, ans);
    }

    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        for(int i = 1; i<=9; i++) {
            solve(low, high, i, 0, ans);
        }
        Collections.sort(ans);
        return ans;
    }
}