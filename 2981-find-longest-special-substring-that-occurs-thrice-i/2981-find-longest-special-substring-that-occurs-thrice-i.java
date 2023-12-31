class Solution {
    public int maximumLength(String s) {
        HashMap<Pair<Character, Integer>, Integer> map = new HashMap<>();
        int n = s.length();

        for(int i = 0; i<n; i++) {
            int count = 1;
            char c = s.charAt(i);
            Pair<Character, Integer> pair = new Pair(c, count);
            map.put(pair, map.getOrDefault(pair, 0) + 1);

            for(int j = i; j<n-1; j++) {
                char a = s.charAt(j);
                char b = s.charAt(j+1);
                if(a == b) {
                    count++;
                    Pair<Character, Integer> curr = new Pair(c, count);
                    map.put(curr, map.getOrDefault(curr, 0) + 1);
                }
                else break;
            }
        }

        int ans = 0;
        for(Map.Entry<Pair<Character, Integer>, Integer> entry : map.entrySet()) {
            if(entry.getValue() >= 3) {
               ans = Math.max(ans, entry.getKey().getValue());
            }
        }

        return ans == 0 ? -1 : ans;
    }
}