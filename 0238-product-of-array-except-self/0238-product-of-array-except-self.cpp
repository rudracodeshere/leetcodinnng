class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);

        output[0] = 1;

        for (int i = 1; i < n; i++) {
            output[i] = nums[i - 1] * output[i - 1];
        }
        int r = 1;
        for(int i = n-1;i>=0;i--){
            output[i]=output[i]*r;
            r *=nums[i];
        }
        return output;
    }
};