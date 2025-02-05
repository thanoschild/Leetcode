class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        if(n != m) return false;
        if(s1.equals(s2)) return true;

        int a = -1, b = -1, count = 0;
        for(int i = 0; i<n; i++) {
            char x = s1.charAt(i);
            char y = s2.charAt(i);
            if(x != y) {
                count++;
                if(a == -1) a = i;
                else if(b == -1) b = i;
            }
        }

        return count == 2 && s1.charAt(a) == s2.charAt(b) && s1.charAt(b) == s2.charAt(a);
    }
}