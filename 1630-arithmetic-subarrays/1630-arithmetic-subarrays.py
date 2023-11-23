class Solution(object):
    def checkArithmeticSubarrays(self, nums, l, r):
        n = len(l)
        ans = []
        
        for i in range(n):
            v = nums[l[i]:r[i] + 1]
            v.sort()
            flag = True
            
            if len(v) > 1:
                diff = v[1] - v[0]
                for j in range(1, len(v) - 1):
                    if diff != v[j+1] - v[j]:
                        flag = False
            else:
                flag = False
            ans.append(flag)
            
        return ans
                        
                
                      

        