class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] indegree = new int[n];
        for(int[] e : edges) {
            indegree[e[1]]++;
        }

        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) ans.add(i);
        }

        return ans.size() == 1 ? ans.get(0) : -1;
    }
}