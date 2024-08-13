class Solution {
    List<List<Integer>> ans;
    private void solve(int idx, int[] arr, List<Integer> curr, int sum) {
        int n = arr.length;
        if(sum == 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for(int i=idx; i<n; i++) {
            if(i > idx && arr[i] == arr[i-1]) continue;
            if(sum < arr[i]) break;
            curr.add(arr[i]);
            solve(i+1, arr, curr, sum - arr[i]);
            curr.remove(curr.size() - 1);
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] arr, int target) {
        ans = new ArrayList<>();
        Arrays.sort(arr);
        List<Integer> curr = new ArrayList<>();
        solve(0, arr, curr, target);
        return ans;
    }
}