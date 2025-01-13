class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        for (int i = 0; i < COLS; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i, ROWS, COLS);
            }
            if (board[ROWS - 1][i] == 'O') {
                dfs(board, ROWS - 1, i, ROWS, COLS);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, ROWS, COLS);
            }
            if (board[i][COLS - 1] == 'O') {
                dfs(board, i, COLS - 1, ROWS, COLS);
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int r, int c, int& ROWS, int& COLS) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != 'O')
            return;
        board[r][c] = 'T';
        dfs(board, r + 1, c, ROWS, COLS);
        dfs(board, r - 1, c, ROWS, COLS);
        dfs(board, r, c + 1, ROWS, COLS);
        dfs(board, r, c - 1, ROWS, COLS);
    }
};