class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int current_sum = 0;
        for(int num:nums){
            current_sum += num;
            ans = max(ans,current_sum);
            if(current_sum<0) current_sum = 0;
        }
        return ans;
    }
};