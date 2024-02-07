class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for(String s : strs) {
            char[] c = s.toCharArray();
            Arrays.sort(c);
            String sortedStr = new String(c);
            map.computeIfAbsent(sortedStr, k -> new ArrayList<>()).add(s);
        }

        List<List<String>> ans = new ArrayList<>();
        for(List<String> value : map.values()) {
            ans.add(value);
        }

        return ans;
    }
}