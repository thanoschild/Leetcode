class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int count = 0, maxFreq = 0;

        for(int it : nums) {
            mp.put(it, mp.getOrDefault(it, 0) + 1);

            if(mp.get(it) > maxFreq) {
                maxFreq = mp.get(it);
                count = 0;
            }

            if(mp.get(it) == maxFreq) count++;
        }

        return count * maxFreq;
    }
}