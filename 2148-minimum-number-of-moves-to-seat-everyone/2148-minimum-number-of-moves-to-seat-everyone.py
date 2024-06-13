class Solution(object):
    def minMovesToSeat(self, seats, students):
        seats.sort()
        students.sort()
        ans , n = 0, len(seats)
        for i in range(n):
            ans += abs(seats[i] - students[i])
        
        return ans
        