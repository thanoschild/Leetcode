class Solution {
    public int minOperations(String s) {
        int count = 0, n = s.length();
        for(int i = 0; i<n; i++) {
            if(s.charAt(i) - '0' != i % 2) count++;
        } 

        return Math.min(count, n - count);
    }
}