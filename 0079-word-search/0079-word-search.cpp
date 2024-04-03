class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int k) {
        if(k == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[k]) return false;

        board[i][j] = '*';
        bool flag = false;
        for(int l = 0; l<4; l++) {
            flag = flag || dfs(board, word, i + dir[l], j + dir[l + 1], k + 1);
        }
        board[i][j] = word[k];
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return false;
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};