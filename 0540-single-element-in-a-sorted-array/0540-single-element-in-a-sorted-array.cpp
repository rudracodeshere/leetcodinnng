class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();

        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int l = 1;
        int r = n - 2;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            bool even = mid % 2 == 0;
            if ((even && nums[mid + 1] == nums[mid]) ||
                (!even && nums[mid - 1] == nums[mid])) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};