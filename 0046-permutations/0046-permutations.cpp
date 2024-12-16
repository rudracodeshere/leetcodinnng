#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> nums) {
        // Base case: If the size of nums is 0, return a vector containing an empty permutation
        if (nums.empty()) {
            return {{}};
        }

        // Base case: If the size of nums is 1, return a single permutation containing nums
        if (nums.size() == 1) {
            return {nums};
        }

        // Take the first element out of nums to permute the rest
        int first = nums[0];
        vector<int> rest(nums.begin() + 1, nums.end());
        vector<vector<int>> subAns = permute(rest);
        vector<vector<int>> ans;

        // Insert the first element into every position of every permutation of the rest
        for (auto& sa : subAns) {
            for (int i = 0; i <= sa.size(); i++) {
                // Insert first at position i
                sa.insert(sa.begin() + i, first);
                ans.push_back(sa);
                
                // Erase the element we just inserted to revert `sa` to its original
                sa.erase(sa.begin() + i);
            }
        }

        return ans;
    }
};