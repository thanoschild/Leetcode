class Solution(object):
    def largestOddNumber(self, num):
        for i in reversed(range(len(num))):
            digit = int(num[i])
            
            if  digit % 2 == 1:
                return num[:i+1]
                
        return ""
        