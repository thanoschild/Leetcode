class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = customers.length;
        int happyCustomers = 0;
        for(int i = 0; i<n; i++) {
            if(grumpy[i] == 0) {
               happyCustomers += customers[i];
               customers[i] = 0;
            } 
        }

        int maxSum = 0, sum = 0;
        for(int i = 0; i<n; i++) {
            sum += customers[i];
            if(i >= minutes) {
                sum -= customers[i - minutes];
            }
            maxSum = Math.max(maxSum , sum);
        }

        return happyCustomers + maxSum;
    }
}