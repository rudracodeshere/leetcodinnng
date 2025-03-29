class Solution {
public:
    void helper(vector < int> &nums, int ind, vector<vector<int>>& ans,
                vector<int>& curr) {
        if (ind == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        helper(nums, ind + 1, ans, curr);
        curr.pop_back();
         while(ind+1<nums.size()&&nums[ind]==nums[ind+1]){
            ind++;
         }
         helper(nums,ind+1,ans,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, 0, ans, curr);
        return ans;
    }
};