class Solution {
    public List<String> stringMatching(String[] words) {
        int n = words.length;
        Arrays.sort(words, (a, b) -> b.length() - a.length());
        HashSet<String> st = new HashSet<>();

        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                if(words[i].contains(words[j])) st.add(words[j]);
            }
        }

        List<String> ans = new ArrayList<>(st);
        return ans;
    }
}