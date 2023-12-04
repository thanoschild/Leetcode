class Solution {
    public String largestGoodInteger(String num) {
        char ans = 0;
        int n = num.length();
        if (n < 3) return "";
        
        for (int i = 2; i < n; i++) {
            if (num.charAt(i) == num.charAt(i - 1) && num.charAt(i) == num.charAt(i - 2)) {
                ans = (char) Math.max(ans, num.charAt(i));
            }
        }

        return ans == 0 ? "" : String.valueOf(ans).repeat(3);
    }
}