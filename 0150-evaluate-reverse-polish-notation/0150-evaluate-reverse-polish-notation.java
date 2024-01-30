class Solution {
    public int evalRPN(String[] tokens) {
        HashMap<String, BiFunction<Long, Long, Long>> mp = new HashMap<>();
        mp.put("+", (a, b) -> a + b);
        mp.put("-", (a, b) -> a - b);
        mp.put("*", (a, b) -> a * b);
        mp.put("/", (a, b) -> a / b);

        Stack<Long> st = new Stack<>();
        for(String s : tokens) {
            if(!mp.containsKey(s)) {
               st.push(Long.parseLong(s));
            }
            else {
                Long a = st.pop();
                Long b = st.pop();
                st.push(mp.get(s).apply(b, a));
            }
        }

        return st.pop().intValue();
    }
}