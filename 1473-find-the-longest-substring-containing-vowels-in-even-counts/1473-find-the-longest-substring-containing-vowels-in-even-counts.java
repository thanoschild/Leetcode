class Solution {
    public int findTheLongestSubstring(String s) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        char[] v = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0, mask = 0;
        mp.put(0, -1);

        for(int i = 0; i<s.length(); i++) {
            char c = s.charAt(i);
            for(int j = 0; j<5; j++) {
                if(c == v[j]) {
                    mask = mask ^ (1 << j);
                    break;
                }
            }

            if(!mp.containsKey(mask)) {
                mp.put(mask, i);
            }

            ans = Math.max(ans, i - mp.get(mask));
        }

        return ans;
    }
}