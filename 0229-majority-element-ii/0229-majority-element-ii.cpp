class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for (int num : nums) {
            if (count1 == 0 && num != el2) {
                count1++;
                el1 = num;
            } else if (count2 == 0 && num != el1) {
                count2++;
                el2 = num;
            } else if (num == el1) {
                count1++;
            } else if (num == el2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == el1) {
                count1++;
            }
        }
        for (int num : nums) {
            if (num == el2) {
                count2++;
            }
        }

        if (count1 > (n / 3))
            ans.push_back(el1);
        if (count2 > (n / 3))
            ans.push_back(el2);
        return ans;
    }
};