class Solution {
    public int numSteps(String s) {
        int n = s.length(), ans = 0, carry = 0;
        for(int i = n - 1; i>0; i--) {
            if(s.charAt(i) - '0' + carry == 1) {
                ans++;
                carry = 1;
            }
            ans++;
        }

        return ans + carry;
    }
}