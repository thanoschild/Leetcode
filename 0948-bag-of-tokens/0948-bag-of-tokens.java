class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int ans = 0, points = 0, i = 0, j = tokens.length - 1;
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                points++;
                ans = Math.max(ans, points);
                i++;
            }
            else if(points > 0) {
                points--;
                power += tokens[j];
                j--;
            }
            else {
                break;
            }
        }

        return ans;
    }
}