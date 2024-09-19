class Solution(object):
    def diffWaysToCompute(self, expression):
        operations = {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y,
        }
        
        def backtrack(left, right):
            ans = []
            for i in range(left, right + 1):
                op = expression[i]
                if op in operations:
                    nums1 = backtrack(left, i-1)
                    nums2 = backtrack(i+1, right)

                    for n1 in nums1:
                        for n2 in nums2:
                            ans.append(operations[op](n1, n2))
                    
            if ans == []:
                ans.append(int(expression[left:right+1]))
            return ans
          
        return backtrack(0, len(expression) - 1)
