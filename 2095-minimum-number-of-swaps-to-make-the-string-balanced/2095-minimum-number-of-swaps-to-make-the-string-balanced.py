class Solution(object):
    def minSwaps(self, s):
        st, count = [], 0

        for c in s:
            if c == '[':
                st.append(c)
            else:
                if st:
                    st.pop() 
                else:
                    count += 1
        
        return (count + 1) // 2
        