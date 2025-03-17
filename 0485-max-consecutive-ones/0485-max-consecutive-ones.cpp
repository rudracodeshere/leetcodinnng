class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = -1;
        int ans = 0;
        int n = nums.size();
        for (int r = 0; r < nums.size(); r++) {
            if (l == -1 && nums[r] == 1) {
                l = r;
            }

            else if (l != -1 && nums[r] == 0) {
                ans = max(ans, r - l);
                l = -1;
            }
        }

        if (l != -1) {
            ans = max(ans, n - l);
        }
        return ans;
    }
};