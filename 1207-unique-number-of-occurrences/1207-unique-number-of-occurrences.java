class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Arrays.sort(arr);
        List<Integer> ans = new ArrayList<>();

        int i = 0, n = arr.length;
        while(i < n) {
            int count = 1, j;
            for(j = i + 1; j<n; j++) {
                if(arr[j] == arr[i]) count++;
                else break;
            }
            ans.add(count);
            i = j;
        }

        Collections.sort(ans);
        for(i = 0; i<ans.size()-1; i++) {
            if(ans.get(i) == ans.get(i+1)) return false;
        }

        return true;
    }
}