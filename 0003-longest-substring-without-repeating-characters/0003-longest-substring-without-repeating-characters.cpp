class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int res = 0;
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            res = max(res, (r - l + 1));
            r++;
        }
        return res;
    }
};