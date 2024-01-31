class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int[] ans = new int[n];
        int hottest = 0;

        for(int i = n - 1; i>=0; i--) {
            int currTemp = temp[i];

            if(currTemp >= hottest) {
                hottest = currTemp;
                continue;
            }

            int days = 1;
            while(temp[i + days] <= currTemp) {
                days += ans[i+days];
            }

            ans[i] = days;
        }

        return ans;
    }
}