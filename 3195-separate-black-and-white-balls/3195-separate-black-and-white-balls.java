class Solution {
    public long minimumSteps(String s) {
        long ans = 0, count = 0;
        for(int i = 0; i<s.length(); i++) {
            if(s.charAt(i) == '1') count++;
            else ans += count;
        }

        return ans;
    }
}