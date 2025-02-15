#include <bits/stdc++.h>
class Solution {
public:
    int util(int m, int n, int i, int j, vector<vector<int>>& memo) {
        if (i >= m || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int ways = 0;
        ways += util(m, n, i + 1, j, memo);
        ways += util(m, n, i, j + 1, memo);
        memo[i][j] = ways;
        return ways;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return util(m, n, 0, 0, memo);
    }
};