class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;

        int l = 0, r = height.size() - 1;

        while (l < r) {
            int minH = min(height[l], height[r]);
            ans = max(ans, minH * (r - l));
            height[l] < height[r] ? l++ : r--;
        }
        return ans;
    }
};