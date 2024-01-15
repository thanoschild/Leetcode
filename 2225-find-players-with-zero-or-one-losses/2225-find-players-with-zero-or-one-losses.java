class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> map = new TreeMap<>();
        for(int[] it : matches) {
            map.put(it[0], map.getOrDefault(it[0], 0));
            map.put(it[1], map.getOrDefault(it[1], 0) + 1);
        }

        List<List<Integer>> ans = new ArrayList<>(2);
        for(int i = 0; i<2; i++) {
            ans.add(new ArrayList<>());
        }

        for(Integer player : map.keySet()) {
            if(map.get(player) <= 1) {
                ans.get(map.get(player)).add(player);
            }
        }

        return ans;
    }
}