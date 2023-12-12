class Solution {
    public int maxProduct(int[] nums) {
        int n1 = 0, n2 = 0;
        for(int num : nums) {
            if(num > n1) {
                n2 = n1;
                n1 = num;
            }
            else{
                n2 = Math.max(n2, num);
            }
        }
        
        return (n1 - 1)*(n2 - 1);
    }
}