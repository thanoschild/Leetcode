class Solution {
    int[] dir = {-1, 0, 1, 0, -1};

    private boolean dfs(char[][] board, String word, int i, int j, int k) {
        if(k == word.length()) return true;
        if(i < 0 || i >= board.length || j < 0 || j >= board[i].length || board[i][j] != word.charAt(k)) {
            return false;
        }

        board[i][j] = '*';
        boolean flag = false;
        for(int l = 0; l<4; l++) {
            flag = flag || dfs(board, word, i + dir[l], j + dir[l + 1], k + 1);
        }
        board[i][j] = word.charAt(k);
        return flag;
    }
    
    public boolean exist(char[][] board, String word) {
        if(word.length() == 0) return false;
        int n = board.length, m = board[0].length;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == word.charAt(0) && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
}