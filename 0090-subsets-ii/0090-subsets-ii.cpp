class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> sub = {};
        dfs(nums, 0, sub, res);
        return res;
    }
    void dfs(vector<int>& nums, int i, vector<int> sub,
             vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        dfs(nums, i + 1, sub, res);

        sub.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;

        dfs(nums, i + 1, sub, res);
    }
};