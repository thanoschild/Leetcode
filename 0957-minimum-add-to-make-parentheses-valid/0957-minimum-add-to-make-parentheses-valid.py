class Solution(object):
    def minAddToMakeValid(self, s):
        _open, _close = 0, 0
        for c in s:
            if c == '(':
                _open += 1
            else:
                if _open > 0:
                    _open -= 1
                else:
                    _close += 1
        
        return _open + _close
        