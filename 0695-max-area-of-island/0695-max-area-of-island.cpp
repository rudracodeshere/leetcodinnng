class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int ans = 1;
        grid[i][j] = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& p : dir) {
            int ni = i + p.first;
            int nj = j + p.second;
            ans += dfs(grid, ni, nj, m, n);
        }

        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int temp = dfs(grid, i, j, m, n);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};