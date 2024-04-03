/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
let dir = [-1, 0, 1, 0, -1];

function dfs(board, word, i, j, k) {
    if(word.length === k) return true;
    if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word[k]) {
        return false;
    }

    board[i][j] = '*';
    let flag = false;
    for(let l = 0; l<4; l++) {
        flag = flag || dfs(board, word, i + dir[l], j + dir[l + 1], k + 1);
    }

    board[i][j] = word[k];
    return flag;
};

var exist = function(board, word) {
    if(word.length == 0) return false;
    let n = board.length, m = board[0].length;

    for(let i = 0; i<n; i++) {
        for(let j = 0; j<m; j++) {
            if(board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
};