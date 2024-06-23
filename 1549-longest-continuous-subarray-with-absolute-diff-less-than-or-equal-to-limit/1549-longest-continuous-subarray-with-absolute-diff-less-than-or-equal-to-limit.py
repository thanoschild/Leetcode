from sortedcontainers import SortedList

class Solution(object):
    def longestSubarray(self, nums, limit):
        ans = 0
        prev = 0
        st = SortedList()

        for i in range(len(nums)):
            st.add(nums[i])
            while st[-1] - st[0] > limit:
                st.remove(nums[prev])
                prev += 1
            ans = max(ans, len(st))

        return ans
        
        