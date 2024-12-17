class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> sub;
        dfs(candidates, target, res, sub, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res,
             vector<int> sub, int i) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (i >= candidates.size() || target < 0)
            return;

        sub.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], res, sub, i + 1);
        sub.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
            i++;
        dfs(candidates, target, res, sub, i + 1);
    }
};