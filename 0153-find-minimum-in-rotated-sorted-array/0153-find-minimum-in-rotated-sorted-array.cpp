class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = INT_MAX;
        while (l <= r) {
            int k = (l + r) / 2;
            res = min(res, nums[k]);
            if (nums[r] <= nums[k]) {
                l = k + 1;
            } else if (nums[r] > nums[k]) {
                r = k - 1;
            } else
                break;
        }
        return res;
    }
};