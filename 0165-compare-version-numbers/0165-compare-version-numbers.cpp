class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int n1 = ver1.size(), n2 = ver2.size();
        int i = 0, j = 0;

        while(i < n1 || j < n2) {
            int num1 = 0, num2 = 0;
            while(i < n1 && ver1[i] != '.') {
                num1 = 10 * num1 + (ver1[i] - '0');
                i++;
            }
            while(j < n2 && ver2[j] != '.') {
                num2 = 10 * num2 + (ver2[j] - '0');
                j++;
            }

            if(num1 > num2) return 1;
            else if(num2 > num1) return -1;
            i++, j++;
        }

        return 0;
    }
};