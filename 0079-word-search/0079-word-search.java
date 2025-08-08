class Solution {
    int dir[] = {-1, 0, 1, 0, -1};

    private boolean dfs(char[][] board, String word, int i, int j, int k, int n, int m) {
        if(k == word.length()) return true;
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word.charAt(k)) return false;

        board[i][j] = '*';
        boolean flag = false;

        for(int d = 0; d<4; d++) {
            flag = flag || dfs(board, word, i + dir[d], j + dir[d+1], k+1, n, m);
        }

        board[i][j] = word.charAt(k);
        return flag;
    }

    public boolean exist(char[][] board, String word) {
        int n = board.length, m = board[0].length;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == word.charAt(0) && dfs(board, word, i, j, 0, n, m)) return true;
            }
        }

        return false;
    }
}