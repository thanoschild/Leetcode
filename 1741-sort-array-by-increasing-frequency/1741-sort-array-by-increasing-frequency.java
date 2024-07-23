class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        List<Integer> list = new LinkedList<>();

        for(int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
            list.add(num);
        }

        Collections.sort(list, (a, b) -> {
            int freq = Integer.compare(mp.get(a), mp.get(b));
            if(freq != 0) return freq;
            else return Integer.compare(b, a);
        });

        for(int i = 0; i<nums.length; i++) nums[i] = list.get(i);
        return nums;
    }
}