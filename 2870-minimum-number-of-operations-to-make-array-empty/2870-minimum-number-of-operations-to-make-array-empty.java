class Solution {
    public int minOperations(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int n : nums) map.put(n, map.getOrDefault(n, 0) + 1);
        int count = 0;

        for(int n : map.values()) {
            if(n == 1) return -1;
            count += n/3;
            if(n%3 != 0) count += 1;
        }

        return count;
    }
}