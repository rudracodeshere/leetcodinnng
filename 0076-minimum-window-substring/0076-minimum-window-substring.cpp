class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())
            return "";
        pair<int, int> ansInd;
        int minLen = INT_MAX;
        map<char, int> mT;
        for (char ch : t) {
            mT[ch]++;
        }
        int l = 0;
        map<char, int> window;
        int have = 0, need = mT.size();
        for (int r = 0; r < s.size(); r++) {
            if (mT.count(s[r])) {
                window[s[r]]++;
                if (window[s[r]] == mT[s[r]]) {
                    have++;
                }
            }
            while (have == need) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    ansInd = {l, r};
                }
                if (mT.count(s[l])) {
                    window[s[l]]--;
                    if (window[s[l]] < mT[s[l]]) {
                        have--;
                    }
                }
                l++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(ansInd.first, minLen);
    }
};