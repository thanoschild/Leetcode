import java.util.*;

class Solution {
    public int[] restoreArray(int[][] nums) {
        int n = nums.length;
        Map<Integer, ArrayList<Integer>> map = new HashMap<>();

        for(int[] it : nums) {
           map.computeIfAbsent(it[0], k -> new ArrayList<>()).add(it[1]);
           map.computeIfAbsent(it[1], k -> new ArrayList<>()).add(it[0]);
        }

        int start = Integer.MIN_VALUE;
        for(Map.Entry<Integer, ArrayList<Integer>> entry : map.entrySet()) {
            if(entry.getValue().size() == 1) {
                start = entry.getKey();
                break;
            }
        }

        int prev = Integer.MIN_VALUE;
        int[] ans = new int[n + 1];
        ans[0] = start;

        for(int i = 1; i<=n; i++) {
            List<Integer> v = map.get(start);
            int curr = (v.get(0) == prev) ? v.get(1) : v.get(0);
            ans[i] = curr;
            prev = start;
            start = curr;
        }

        return ans;
    }
}