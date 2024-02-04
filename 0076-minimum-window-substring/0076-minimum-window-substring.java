class Solution {
    public String minWindow(String s, String t) {
        int n = s.length(), m = t.length();
        if(n == 0 || m == 0 || m > n) return "";
        int[] freq = new int[256];

        for(char c : t.toCharArray()) {
            freq[c]++;
        }

        int start = 0, end = 0, len = Integer.MAX_VALUE, ans = 0, count = 0;
        while(end < n) {
            char endChar = s.charAt(end);
            if(freq[endChar] > 0) count++;
            freq[endChar]--;
            while(count == m) {
                char startChar = s.charAt(start);
                if(len > end - start + 1) {
                    len = end - start + 1;
                    ans = start;
                }
                freq[startChar]++;
                if(freq[startChar] > 0) count--;
                start++;
            }
            end++;
        }

        return len == Integer.MAX_VALUE ? "" : s.substring(ans, ans + len);
    }
}