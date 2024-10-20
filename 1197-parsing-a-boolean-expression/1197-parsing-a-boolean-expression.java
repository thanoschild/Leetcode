class Solution {
    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();

        for(char c : expression.toCharArray()) {
            if(c == '(' || c == ',') continue;
            if(c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') st.add(c);
            else if(c == ')') {
                boolean hasTrue = false, hasFalse = false;
                while(st.peek() != '!' && st.peek() != '&' && st.peek() != '|') {
                    char t = st.pop();
                    if(t == 't') hasTrue = true;
                    if(t == 'f') hasFalse = true;
                }

                char t = st.pop();
                if(t == '!') st.add(hasTrue ? 'f' : 't');
                else if(t == '&') st.add(hasFalse ? 'f' : 't');
                else st.add(hasTrue ? 't' : 'f');
            }
        }

        return st.peek() == 't';
    }
}