class Solution {
    public int maximumLength(String s) {
        HashMap<String, Integer> map = new HashMap<>();
        int n = s.length();
        
        for(int i = 0; i<n; i++) {
            String curr = "";
            char c = s.charAt(i);
            curr += c;
            map.put(curr, map.getOrDefault(curr, 0) + 1);
            
            for(int j = i; j<n-1; j++) {
                char a = s.charAt(j);
                char b = s.charAt(j+1);
                if(a == b) {
                    curr += a;
                    map.put(curr, map.getOrDefault(curr, 0) + 1);
                }
                else break;
            }
        }
        
        int ans = 0;
        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            if(entry.getValue() >= 3) {
                ans = Math.max(ans, entry.getKey().length());
            }
        }
        
        return ans == 0 ? -1 : ans;
    }
}