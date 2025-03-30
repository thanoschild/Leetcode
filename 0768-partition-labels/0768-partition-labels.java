class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        int[] pos = new int[26];

        for(int i = n - 1; i>=0; i--) {
            int c = s.charAt(i) - 'a';
            if(pos[c] == 0) pos[c] = i;
        }

        List<Integer> ans = new ArrayList<>();
        int len = 0, position = -1;
        for(int i = 0; i<n; i++) {
            int c = s.charAt(i) - 'a';
            len++;
            position = Math.max(position, pos[c]);
            if(position == i) {
                ans.add(len);
                len = 0;
                position = -1;
            }
        }

        return ans;
    }
}