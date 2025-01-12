class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        vector<vector<int>> res;

        for (int c = 0; c < COLS; c++) {
            dfs(heights, 0, c, pac, ROWS, COLS);
            dfs(heights, ROWS - 1, c, atl, ROWS, COLS);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(heights, r, 0, pac, ROWS, COLS);
            dfs(heights, r, COLS - 1, atl, ROWS, COLS);
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> & heights, int r, int c,
             vector<vector<bool>> &ocean, int & ROWS, int & COLS) {

        ocean[r][c] = true;

        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
                
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !ocean[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, ocean, ROWS, COLS);
            }
        }
    }
};