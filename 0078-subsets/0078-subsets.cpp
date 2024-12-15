class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        dfs(nums, res, sub, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int> sub,
             int i) {
        if (i >= nums.size()) {
            res.push_back(sub);
            return;
        }
        dfs(nums, res, sub, i + 1);
        sub.push_back(nums[i]);
        dfs(nums, res, sub, i + 1);
        //sub.pop_back();
    }
};