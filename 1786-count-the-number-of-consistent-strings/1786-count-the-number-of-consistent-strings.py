class Solution(object):
    def countConsistentStrings(self, allowed, words):
        st = set()
        for c in allowed:
            st.add(c)

        count = 0
        flag = True

        for s in words:
            flag = True
            for c in s:
                if c not in st:
                    flag = False
                    break
            
            if flag:
                count += 1
        
        return count


        