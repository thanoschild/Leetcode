class Solution {
    public String customSortString(String order, String s) {
        HashSet<Character> st = new HashSet<>();
        StringBuilder ans = new StringBuilder();

        for(char c : order.toCharArray()) {
            for(int i = 0; i<s.length(); i++) {
                if(s.charAt(i) == c) ans.append(c);
            }
            st.add(c);
        }

        for(char c : s.toCharArray()) {
            if(!st.contains(c)) ans.append(c);
        }

        return ans.toString();
    }
}