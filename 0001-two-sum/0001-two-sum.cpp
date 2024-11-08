#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans(2);
        
    for(int i = 0;i<nums.size();i++){
        if(mp.count(target-nums[i])){
            ans[1]=i;
            ans[0] =mp[target-nums[i]];
        }
        else{
            mp[nums[i]] = i;
        }
    }

return ans;
        }
    
};