class Solution {
    public int findSpecialInteger(int[] arr) {
        int count = 1, n = arr.length;
        if(n == 1) return arr[0];
        
        for(int i = 1; i<n; i++) {
            if(arr[i] == arr[i-1]) count++;
            else count = 1;
            
            if(count > n/4) return arr[i];
        }
        
        return -1;
    }
}