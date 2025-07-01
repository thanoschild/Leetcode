class Solution {
    public int possibleStringCount(String word) {
        int ans = 0, count = 1, n = word.length();

        for(int i = 1; i<n; i++) {
            char a = word.charAt(i);
            char b = word.charAt(i - 1);
            if(a == b) count++;
            else {
                ans += (count - 1);
                count = 1;
            }
        }

        if(count > 1) ans += (count - 1);

        return ans + 1;
    }
}