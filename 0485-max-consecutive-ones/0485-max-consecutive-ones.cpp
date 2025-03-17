class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        for (int num : nums) {
            if (num == 1) {
                temp++;
            } else {
                ans = max(ans, temp);
                temp = 0;
            }
        }
        return max(ans, temp);
    }
};