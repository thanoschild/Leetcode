class Solution(object):
    def bagOfTokensScore(self, tokens, power):
        tokens.sort()
        ans, points, i, j = 0, 0, 0, len(tokens)-1
        while i <= j:
            if power >= tokens[i]:
                power -= tokens[i]
                points += 1
                ans = max(ans, points)
                i += 1
            elif points > 0:
                points -= 1
                power += tokens[j]
                j -= 1
            else:
                break
            
        return ans
        