class Solution(object):
    def checkIfExist(self, arr):
        st = set()
        for it in arr:
            if it*2 in st:
                return True
            if it%2 == 0 and it//2 in st:
                return True
            st.add(it)
            
        return False
        