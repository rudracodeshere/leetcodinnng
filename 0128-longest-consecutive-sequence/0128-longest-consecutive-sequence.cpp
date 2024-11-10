class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; 

        set<int> mp(nums.begin(), nums.end()); 
        int prev = *mp.begin() - 1;
        int len = 0, tempL = 0;

        for (auto& i : mp) {
            if (i == prev + 1) {
                tempL++;  \
            } else {
                len = max(len, tempL);  
                tempL = 1;             
            }
            prev = i;
        }
        return max(len, tempL); 
    }
};