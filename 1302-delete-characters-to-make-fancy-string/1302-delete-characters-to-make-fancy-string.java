class Solution {
    public String makeFancyString(String s) {
        StringBuilder ans = new StringBuilder();
        ans.append(s.charAt(0));
        int n = s.length(), count = 1;

        for(int i = 1; i<n; i++) {
            char a = s.charAt(i);
            char b = ans.charAt(ans.length() - 1);
            if(a == b) {
                count++;
                if(count < 3) ans.append(a);
            } else {
                ans.append(a);
                count = 1;
            }
        }

        return ans.toString();
    }
}