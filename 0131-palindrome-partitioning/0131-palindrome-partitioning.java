class Solution {
    private boolean check(String s, int i, int j) {
        while(i < j) {
            if(s.charAt(i++) != s.charAt(j--)) return false;
        }
        return true;
    }
    
    private void solve(String s, int idx, List<String> curr, List<List<String>> ans) {
        int n = s.length();
        if(idx == n) {
            ans.add(new ArrayList<>(curr));
        }

        for(int i = idx; i<n; i++) {
            if(check(s, idx, i)) {
                curr.add(s.substring(idx, i + 1));
                solve(s, i + 1, curr, ans);
                curr.remove(curr.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        if(s.length() == 0) return ans;
        List<String> curr = new ArrayList<>();
        solve(s, 0, curr, ans);
        return ans;
    }
}