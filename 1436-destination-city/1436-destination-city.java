class Solution {
    public String destCity(List<List<String>> paths) {
        int m = paths.size();
        HashMap<String, Integer> mp = new HashMap<>();

        for (int i = 0; i < m; i++) {
            mp.put(paths.get(i).get(0), mp.getOrDefault(paths.get(i).get(0), 0) + 1);
        }

        for (int i = 0; i < m; i++) {
            if (mp.getOrDefault(paths.get(i).get(1), 0) < 1) {
                return paths.get(i).get(1);
            }
        }

        return "thanoschild";
    }
}