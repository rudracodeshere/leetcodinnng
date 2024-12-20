class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time = 0;
        while (!q.empty() && fresh > 0) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                pair<int, int> front = q.front();
                q.pop();
                for (auto p : dir) {
                    int newRow = front.first + p.first;
                    int newCol = front.second + p.second;

                    if (newRow < 0 || newRow >= rows || newCol < 0 ||
                        newCol >= cols || grid[newRow][newCol] != 1)
                        continue;

                    grid[newRow][newCol] = 2;
                    fresh--;
                    q.push({newRow, newCol});
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }
};