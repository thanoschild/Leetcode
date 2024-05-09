class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Integer[] boxedArray = Arrays.stream(happiness).boxed().toArray(Integer[]::new);
        Arrays.sort(boxedArray, (a, b) -> b - a);
        long ans = 0;

        for(int i = 0; i<k; i++) {
            boxedArray[i] = Math.max(0, boxedArray[i] - i);
            ans += boxedArray[i];
        }

        return ans;
    }
}