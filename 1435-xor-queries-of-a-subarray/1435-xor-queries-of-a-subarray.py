class Solution(object):
    def xorQueries(self, arr, queries):
        xors, ans, _xor = [], [], 0

        for n in arr:
            _xor ^= n
            xors.append(_xor)

        for q in queries:
            if q[0] == 0:
                ans.append(xors[q[1]])
            else: ans.append(xors[q[1]] ^ xors[q[0] - 1])
        
        return ans

        