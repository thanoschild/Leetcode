class Solution {
    public boolean halvesAreAlike(String s) {
        HashSet<Character> st = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        int n = s.length();
        int count1 = 0, count2 = 0;

        for(int i = 0; i<n/2; i++) {
            char a = s.charAt(i);
            char b = s.charAt(i + n/2);
            if(st.contains(a)) count1++;
            if(st.contains(b)) count2++;
        }

        return count1 == count2;
    }
}