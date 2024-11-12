class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l(height.size(), 0);
        vector<int> r(height.size(), 0);
        vector<int> minArr(height.size());
        for (int i = 1; i < height.size(); i++) {
            l[i] = max(l[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            r[i] = max(r[i + 1], height[i + 1]);
        }

        for (int i = 0; i < height.size(); i++) {
            minArr[i] = min(l[i], r[i]);
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            int temp = minArr[i] - height[i];
            if (temp <= 0)
                temp = 0;
            ans += temp;
        }
        return ans;
    }
};