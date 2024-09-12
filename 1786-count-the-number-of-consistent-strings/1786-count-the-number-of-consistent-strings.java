class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        HashSet<Character> st = new HashSet<>();
        for(char c : allowed.toCharArray()) st.add(c);
        int count = 0;
        boolean flag = true;

        for(String s : words) {
            flag = true;
            for(char c : s.toCharArray()) {
                if(!st.contains(c)) {
                    flag = false;
                    break;
                }
            }

            if(flag) count++;
        }

        return count;
    }
}