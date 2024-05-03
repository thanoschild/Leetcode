class Solution {
    public int compareVersion(String ver1, String ver2) {
        int n1 = ver1.length(), n2 = ver2.length();
        int i = 0, j = 0;

        while(i < n1 || j < n2) {
            int num1 = 0, num2 = 0;
            while(i < n1 && ver1.charAt(i) != '.') {
                num1 = num1*10 + (ver1.charAt(i) - '0');
                i++;
            }
            while(j < n2 && ver2.charAt(j) != '.') {
                num2 = num2*10 + (ver2.charAt(j) - '0');
                j++;
            }

            if(num1 > num2) return 1;
            else if(num2 > num1) return -1;
            i++; j++;
        }

        return 0;
    }
}