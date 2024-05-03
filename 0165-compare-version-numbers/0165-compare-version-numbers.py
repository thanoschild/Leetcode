class Solution(object):
    def compareVersion(self, ver1, ver2):
        n1, n2 = len(ver1), len(ver2)
        i, j = 0, 0

        while i < n1 or j < n2:
            num1, num2 = 0, 0
            while i < n1 and ver1[i] != '.':
                num1 = num1*10 + (ord(ver1[i]) - ord('0'))
                i += 1
            while j < n2 and ver2[j] != '.':
                num2 = num2*10 + (ord(ver2[j]) - ord('0'))
                j += 1
            
            if num1 > num2:
                return 1
            elif num2 > num1:
                return -1
            i += 1
            j += 1
            
        return 0
        