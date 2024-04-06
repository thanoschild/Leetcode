class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> st = new Stack<>();
        char[] chars = s.toCharArray();

        for(int i = 0; i<chars.length; i++) {
            if(chars[i] == '(') st.push(i);
            else if(chars[i] == ')') {
                if(st.isEmpty()) chars[i] = '*';
                else st.pop();
            }
        }

        while(!st.isEmpty()) chars[st.pop()] = '*';

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i<chars.length; i++) {
            if(chars[i] != '*') ans.append(chars[i]);
        }

        return ans.toString();
    }
}