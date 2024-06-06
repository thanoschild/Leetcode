class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        n = len(hand)
        if n % groupSize != 0:
            return False
        
        count = Counter(hand)
        
        for key in sorted(count):
            if count[key] > 0:
                for i in range(groupSize-1, -1, -1):
                    if count[key + i] < count[key]:
                        return False
                    count[key + i] -= count[key]
        
        return True
        