class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int> st;
        int l = 0, r = 0;
        int ans = 0;
        while (r < n) {
            if (!st.contains(s[r])) {
                ans = max(ans, r - l + 1);

            } else {
                while (l <= r && st.contains(s[r])) {
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            r++;
        }
        return ans;
    }
};