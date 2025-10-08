class Solution {
    int findIndex(int spell, int[] potions, long success) {
        int ans = -1, start = 0, end = potions.length - 1;
        while(start <= end) {
            int mid = (end - start) / 2 + start;
            long currVal = (long) potions[mid] * spell;
            if(currVal >= success) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n = spells.length, m = potions.length;
        int[] ans = new int[n];

        for(int i = 0; i<n; i++) {
            int pos = findIndex(spells[i], potions, success);
            if(pos == -1) ans[i] = 0;
            else {
                ans[i] = m - pos;
            }
        }

        return ans;
    }
}