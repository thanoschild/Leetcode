class Solution {
    public String reversePrefix(String word, char ch) {
        StringBuilder ans = new StringBuilder();
        boolean flag = true;

        for(char c : word.toCharArray()) {
            if(c == ch && flag) {
                ans.append(c);
                ans.reverse();
                flag = false;
            }
            else {
                ans.append(c);
            }
        }

        return ans.toString();
    }
}