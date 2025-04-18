class Solution {
    public String countAndSay(int n) {
        if(n == 0) return "";
        String ans = "1";

        while(--n > 0) {
            StringBuilder curr = new StringBuilder();
            for(int i = 0; i<ans.length(); i++) {
                int count = 1;
                while(i + 1 < ans.length() && ans.charAt(i) == ans.charAt(i + 1)) {
                    count++;
                    i++;
                }
                curr.append(count).append(ans.charAt(i));
            }

            ans = curr.toString();
        }

        return ans;
    }
}