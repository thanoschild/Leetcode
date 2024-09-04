class Solution {
    private int sumDigit(int num) {
        int ans = 0;
        while(num > 0) {
            ans += num % 10;
            num /= 10;
        }

        return ans;
    }

    public int getLucky(String s, int k) {
        int sum = 0;
        for(char c : s.toCharArray()) {
            int val = (c - 'a' + 1);
            while(val > 0) {
                sum += val % 10;
                val /= 10;
            }
        }
        
        while(k > 1) {
            sum = sumDigit(sum);
            k--;
        }

        return sum;
    }
}