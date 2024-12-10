class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        HashMap<String, Integer> mp = new HashMap<>();
        
        for(int i = 0; i<n; i++) {
            String str = "";
            char c = s.charAt(i);
            str += c;
            mp.put(str, mp.getOrDefault(str, 0)+1);

            for(int j = i; j<n-1; j++) {
                char a = s.charAt(j);
                char b = s.charAt(j+1);
                if(a == b) {
                    str += a;
                    mp.put(str, mp.getOrDefault(str, 0)+1);
                } else break;
            }
        }

        int ans = 0;
        for(Map.Entry<String, Integer> entry : mp.entrySet()) {
            if(entry.getValue() >= 3) {
                ans = Math.max(ans, entry.getKey().length());
            }
        }

        return ans == 0 ? -1 : ans;
    }
}