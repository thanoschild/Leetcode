class Solution {
    public void merge(int[] nums, int start, int mid, int end) {
        int n1 = mid - start + 1;
        int n2 = end - mid;
        int[] a1 = new int[n1];
        int[] a2 = new int[n2];

        for(int i = 0; i<n1; i++){
            a1[i] = nums[start+i];
        }
        for(int i = 0; i<n2; i++){
            a2[i] = nums[mid + i + 1];
        }

        int p = 0, q = 0, r = start;
        while((p < n1) && (q < n2)){
            if(a1[p] < a2[q]){
                nums[r] = a1[p];
                p++;
                r++;
            }
            else{
                nums[r] = a2[q];
                q++;
                r++;
            }
        }

        while(p < n1){
            nums[r] = a1[p];
            p++;
            r++; 
        }

        while(q < n2){
            nums[r] = a2[q];
            q++; 
            r++;
        }
    }

    public void mergesort(int[] nums, int start, int end) {
        if(start < end){
            int mid = (start + end)/2;
            mergesort(nums, start, mid);
            mergesort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }

    public int[] sortArray(int[] nums) {
        int n = nums.length;
        mergesort(nums, 0, n - 1);
        return nums;
    }
}