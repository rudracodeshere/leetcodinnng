class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() == 0)
            return {{}};

        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> subAns = permute(temp);
        vector<vector<int>> ans;
        for (auto& sa : subAns) {
            for (int i = 0; i <= sa.size(); i++) {
                sa.insert(sa.begin() + i, nums[0]);
                ans.push_back(sa);
                sa.erase(sa.begin() + i);
            }
        }
        return ans;
    }
};