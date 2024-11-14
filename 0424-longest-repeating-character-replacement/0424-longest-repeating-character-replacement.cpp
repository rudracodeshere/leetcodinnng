class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;  
        int l = 0;    
        int maxf = 0;  
        map<char, int> mp;

        for (int r = 0; r < s.size(); ++r) {
            mp[s[r]]++; 
            maxf = max(maxf, mp[s[r]]);

            if ((r - l + 1) - maxf > k) {
                mp[s[l]]--;  
                l++;         
            }

           
            res = max(res, r - l + 1);
        }

        return res;
    }
};