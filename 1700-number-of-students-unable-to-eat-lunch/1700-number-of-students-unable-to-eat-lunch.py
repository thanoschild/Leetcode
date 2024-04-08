class Solution(object):
    def countStudents(self, students, sandwiches):
        freq = [0] * 2
        n = len(students)
        i = 0

        for x in students:
            freq[x] += 1
        
        while i < n and freq[sandwiches[i]] > 0:
            freq[sandwiches[i]] -= 1
            i += 1
        
        return n - i
        