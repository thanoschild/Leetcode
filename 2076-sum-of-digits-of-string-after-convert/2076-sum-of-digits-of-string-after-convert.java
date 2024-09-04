class Solution {
    public int getLucky(String s, int k) {
        StringBuilder num = new StringBuilder();

        for (char c : s.toCharArray()) {
            num.append((c - 'a') + 1);
        }

        while (k-- > 0) {
            int temp = 0;
            for (char c : num.toString().toCharArray()) {
                temp += (c - '0'); 
            }
            num = new StringBuilder(Integer.toString(temp));
        }

        return Integer.parseInt(num.toString());
    }
}