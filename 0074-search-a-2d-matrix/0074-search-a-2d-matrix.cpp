class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows - 1;
        int ansRow = -1;
        // finding the correct row first

        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[mid][0] <= target && matrix[mid][cols - 1] >= target) {
                ansRow = mid;
                break;
            }
            if (matrix[mid][0] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (ansRow == -1)
            return false;
        start = 0, end = cols - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[ansRow][mid] == target) {
                return true;
            } else if (matrix[ansRow][mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};