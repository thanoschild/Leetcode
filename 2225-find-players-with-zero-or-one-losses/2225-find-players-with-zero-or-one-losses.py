class Solution(object):
    def findWinners(self, matches):
        player_count = defaultdict(int)
        for match in matches:
            player_count[match[0]] += 0
            player_count[match[1]] += 1

        sorted_players = OrderedDict(sorted(player_count.items()))
        ans = [[] for _ in range(2)]

        for player, count in sorted_players.items():
            if count <= 1:
                ans[count].append(player)

        return ans
        