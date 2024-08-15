class Solution(object):
    def lemonadeChange(self, bills):
        fives, tens = 0, 0
        for bill in bills:
            if bill == 5:
                fives += 1
            elif bill == 10:
                tens += 1
                fives -= 1
            elif tens > 0:
                tens -= 1
                fives -= 1
            else:
                fives -= 3
            
            if fives < 0:
                return False
        
        return True
        