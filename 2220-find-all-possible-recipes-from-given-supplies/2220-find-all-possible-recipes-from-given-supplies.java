class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        int n = recipes.length;
        Map<String, ArrayList<String>> edges = new HashMap<>();
        Map<String, Integer> indegree = new HashMap<>();

        for(int i = 0; i<n; i++) {
            indegree.put(recipes[i], ingredients.get(i).size());
            for(String ingredient : ingredients.get(i)) {
                edges.computeIfAbsent(ingredient, k -> new ArrayList<>()).add(recipes[i]);
            }
        }

        Queue<String> pq = new LinkedList<>();
        for(String supply : supplies) {
            pq.add(supply);
        }

        List<String> ans = new ArrayList<>();
        while(!pq.isEmpty()) {
            String item = pq.poll();

            if(indegree.containsKey(item)) {
                ans.add(item);
            }

            for(String recipe : edges.getOrDefault(item, new ArrayList<>())) {
                indegree.put(recipe, indegree.get(recipe) -1);
                if(indegree.get(recipe) == 0) {
                    pq.add(recipe);
                }
            }
        }

        return ans;
    }
}