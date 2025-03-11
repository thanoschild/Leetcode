class Solution {
    public int maxProduct(int[] arr) {
        int n = arr.length, ans = Integer.MIN_VALUE, pro = 1;
    
        for(int i = 0; i<n; i++) {
            pro *= arr[i];
            ans = Math.max(pro, ans);
            if(pro == 0) pro = 1;
        }
        
        pro = 1;
        for(int i = n - 1; i>=0; i--) {
            pro *= arr[i];
            ans = Math.max(ans, pro);
            if(pro == 0) pro = 1;
        }
        
        return ans;
    }
}