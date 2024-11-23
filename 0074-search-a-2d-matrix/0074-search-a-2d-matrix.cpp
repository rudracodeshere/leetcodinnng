class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0;
        int bottom = rows - 1;

        while (top <= bottom) {
            int row = (top + bottom) / 2;
            if (matrix[row][cols - 1] < target) {
                top = row + 1;
            } else if (matrix[row][0] > target) {
                bottom = row - 1;
            } else {
                break;
            }
        }

        if (!(top <= bottom))
            return false;
        int row = (top + bottom) / 2;
        int l = 0;
        int r = cols - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] > target)
                r = mid - 1;
            else if (matrix[row][mid] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};