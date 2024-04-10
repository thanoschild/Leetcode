class Solution(object):
    def deckRevealedIncreasing(self, deck):
        n = len(deck)
        deck.sort()
        pq = collections.deque(range(n))
        ans = [0] * n

        for i in range(n):
            ans[pq.popleft()] = deck[i]
            if pq:
                pq.append(pq.popleft())

        return ans
        