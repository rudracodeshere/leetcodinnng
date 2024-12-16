class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(candidates, target, res, curr, 0, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res,
             vector<int> curr, int sum, int i) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }
        if (i >= candidates.size() || sum > target) {
            return;
        }

        dfs(candidates, target, res, curr, sum, i + 1);
        curr.push_back(candidates[i]);
        dfs(candidates, target, res, curr, sum + candidates[i], i);
    }
};