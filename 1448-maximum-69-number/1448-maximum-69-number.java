class Solution {
    public int maximum69Number (int num) {
        char[] chars = String.valueOf(num).toCharArray();
        int n = chars.length;

        for(int i = 0; i<n; i++) {
            if(chars[i] == '6') {
                chars[i] = '9';
                break;
            }
        }

        return Integer.parseInt(new String(chars));
    }
}