class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> mp = new HashMap<>();
        for(String s : (s1 + " " + s2).split(" ")) {
            mp.put(s, mp.getOrDefault(s, 0) + 1);
        }

        List<String> ans = new ArrayList<>();
        for(String s : mp.keySet()) {
            if(mp.get(s) == 1) ans.add(s);
        }

        return ans.toArray(new String[0]);
    }
}