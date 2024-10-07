class Solution {
    public int minLength(String s) {
        Stack<Character> st = new Stack<>();
        for(char c : s.toCharArray()) {
            if(!st.isEmpty() && ((c == 'B' && st.peek() == 'A') || (c == 'D' && st.peek() == 'C'))) {
                st.pop();
            } else st.add(c);
        }

        return st.size();
    }
}