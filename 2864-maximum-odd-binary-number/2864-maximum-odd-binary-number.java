class Solution {
    public String maximumOddBinaryNumber(String s) {
        int ones = 0, zeros = 0;
        for(char c : s.toCharArray()) {
            if(c == '1') ones++;
            else zeros++;
        }

        String ans = "";
        ones--;
        while(ones-- > 0) ans += '1';
        while(zeros-- > 0) ans += '0';
        ans += '1';

        return ans;
    }
}