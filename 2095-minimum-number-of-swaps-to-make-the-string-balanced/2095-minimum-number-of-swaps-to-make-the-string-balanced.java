class Solution {
    public int minSwaps(String s) {
        Stack<Character> st = new Stack<>();
        int count = 0;

        for(char c : s.toCharArray()) {
            if(c == '[') st.add(c);
            else {
                if(!st.isEmpty()) st.pop();
                else count++;
            }
        }

        return (count + 1)/2;
    }
}