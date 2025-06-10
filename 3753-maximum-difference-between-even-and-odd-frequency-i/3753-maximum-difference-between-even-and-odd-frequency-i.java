class Solution {
    public int maxDifference(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int minEven = Integer.MAX_VALUE, maxOdd = Integer.MIN_VALUE;
        for(char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        for(char key : mp.keySet()) {
            if((mp.get(key) & 1) == 0) {
                minEven = Math.min(minEven, mp.get(key));
            } else {
                maxOdd = Math.max(maxOdd, mp.get(key));
            }
        }
        
        return maxOdd - minEven;
    }
}