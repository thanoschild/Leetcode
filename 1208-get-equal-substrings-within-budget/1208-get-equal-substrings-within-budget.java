class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length(), i = 0, j = 0;
        
        while(i < n) {
            int a = s.charAt(i) - 'a';
            int b = t.charAt(i) - 'a';
            maxCost -= Math.abs(a - b);
            if(maxCost < 0) {
                int a1 = s.charAt(j) - 'a';
                int b1 = t.charAt(j) - 'a';
                maxCost += Math.abs(a1 - b1);
                j++;
            }
            i++;
        }

        return i - j;
    }
}