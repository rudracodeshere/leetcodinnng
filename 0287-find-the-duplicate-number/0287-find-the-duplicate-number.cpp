class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // bruteforce
        //  for (int i = 0; i < nums.size(); i++) {
        //      for (int j = i + 1; j < nums.size(); j++) {
        //          if (nums[i] == nums[j])
        //              return nums[i];
        //      }
        //  }
        //  return INT_MIN;

        set<int> st;
        for (int num : nums) {
            if (st.contains(num))
                return num;
            st.insert(num);
        }
        return INT_MIN;
    }
};