class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_map<int, int> mp;
        int longest = 1;
        
        for (int num : nums) {
           
            if (mp.count(num) > 0) continue;
            
            int left = mp.count(num - 1) ? mp[num - 1] : 0;
            int right = mp.count(num + 1) ? mp[num + 1] : 0;

            int total = left + right + 1;
            
        
            mp[num] = total;
  
            if (left > 0) mp[num - left] = total;
            if (right > 0) mp[num + right] = total;
            
            longest = max(longest, total);
        }
        
        return longest;
    }
};