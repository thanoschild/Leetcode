class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        int n = nums.size();
        int m = 0;
        Map<Integer, List<Integer>> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int k = nums.get(i).size();
            m = Math.max(m, k);
            for (int j = 0; j < k; j++) {
                mp.computeIfAbsent(i + j, key -> new ArrayList<>()).add(nums.get(i).get(j));
            }
        }

        List<Integer> ansList = new ArrayList<>();
        for (int i = 0; i < n + m - 1; i++) {
            List<Integer> temp = mp.get(i);
            if (temp != null) {
                for (int j = temp.size() - 1; j >= 0; j--) {
                    ansList.add(temp.get(j));
                }
            }
        }

        int[] ans = new int[ansList.size()];
        for (int i = 0; i < ansList.size(); i++) {
            ans[i] = ansList.get(i);
        }

        return ans;
    }
}