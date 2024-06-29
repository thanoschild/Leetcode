class Solution {
    public void dfs(int x, int curr, List<List<Integer>> ans, List<List<Integer>> child) {
        for (int it : child.get(curr)) {
            if (ans.get(it).isEmpty() || ans.get(it).get(ans.get(it).size() - 1) != x) {
                ans.get(it).add(x);
                dfs(x, it, ans, child);
            }
        }
    }
    
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> ans = new ArrayList<>();
        List<List<Integer>> child = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            ans.add(new ArrayList<>());
            child.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            child.get(e[0]).add(e[1]);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, i, ans, child);
        }

        return ans;
    }
}