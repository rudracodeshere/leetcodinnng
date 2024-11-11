class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size())
            return false;
        int l = 0;
        int r = 0;
        int count = 0;
        while (r < t.size()) {
            if (s[l] == t[r]) {
                l++;
                count++;
            }
            r++;
        }
        return count == s.size();
    }
};