class Solution(object):
    def evalRPN(self, tokens):
        mp = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
            "/": lambda a, b: int(float(a)/b) 
        }

        st = deque()
        for s in tokens:
            if s not in mp:
                st.append(int(s))
            else:
                a = st.pop()
                b = st.pop()
                st.append(mp[s](b, a))
        
        return st.pop()
        