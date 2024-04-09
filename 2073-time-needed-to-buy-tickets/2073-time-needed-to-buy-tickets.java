class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        for(int i = 0; i<tickets.length; i++) {
            int val = i > k ? tickets[k] - 1 : tickets[k];
            ans += Math.min(tickets[i], val);
        }

        return ans;
    }
}