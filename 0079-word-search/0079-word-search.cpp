class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k, int n, int m) {
        if(k == word.size()) return true;
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[k]) return false;

        board[i][j] = '*';
        bool flag = false;

        for(int d = 0; d<4; d++) {
            flag = flag || dfs(board, word, i + dir[d], j + dir[d+1], k+1, n, m);
        }

        board[i][j] = word[k];
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0, n, m)) return true;
            }
        }

        return false;
    }
};