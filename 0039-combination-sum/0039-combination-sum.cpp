class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>>& ans, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (target < 0 || index == candidates.size()) {
            return;
        }

        curr.push_back(candidates[index]);
        helper(candidates, target - candidates[index], index, ans, curr);
        curr.pop_back();

        helper(candidates, target, index + 1, ans, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, 0, ans, curr);
        return ans;
    }
};
