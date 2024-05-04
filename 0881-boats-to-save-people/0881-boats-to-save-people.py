class Solution(object):
    def numRescueBoats(self, people, limit):
        people.sort()
        i, j, ans = 0, len(people) - 1, 0

        while i <= j:
            sum = people[i] + people[j]
            if sum <= limit:
                ans += 1
                i += 1
                j -= 1
            else:
                ans += 1
                j -= 1
            
        return ans
        