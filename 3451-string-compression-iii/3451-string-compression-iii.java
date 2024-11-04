class Solution {
    public String compressedString(String word) {
        StringBuilder ans = new StringBuilder();
        int n = word.length(), count = 1;
        char prev = word.charAt(0);

        for(int i = 1; i<n; i++) {
            char c = word.charAt(i);
            if(prev == c && count < 9) count++;
            else {
                ans.append(count).append(prev);
                prev = c;
                count = 1;
            }
        }

        ans.append(count).append(prev);
        return ans.toString();
    }
}