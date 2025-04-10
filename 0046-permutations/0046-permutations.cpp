class Solution {
public:
void helper(int index, vector<vector<int>>&ans,vector<int>&nums){
    if(index == nums.size()){
        ans.push_back(nums);
    }
    for(int i = index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        helper(index+1,ans,nums);
        swap(nums[i],nums[index]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,ans,nums);
        return ans;
    }
};