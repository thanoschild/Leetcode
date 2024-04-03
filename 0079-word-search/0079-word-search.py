class Solution(object):
    def __init__(self):
        self.dir = [-1, 0, 1, 0, -1]

    def dfs(self, board, word, i, j, k):
        if k == len(word):
            return True
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[k]:
            return False
        
        board[i][j] = '*'
        flag = False
        for l in range(4):
            flag = flag or self.dfs(board, word, i + self.dir[l], j + self.dir[l + 1], k + 1)
        
        board[i][j] = word[k]
        return flag

    def exist(self, board, word):
        if len(word) == 0:
            return False
        n, m = len(board), len(board[0])

        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0] and self.dfs(board, word, i, j, 0):
                    return True
        
        return False
