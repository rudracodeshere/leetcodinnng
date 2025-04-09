class Solution {
public:
    bool isPali(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(string s, int i, vector<vector<string>>& res,
                vector<string>& curr) {

        if (i == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            string temp = s.substr(i, j - i + 1);
            if (isPali(s, i, j)) {
                curr.push_back(temp);
                helper(s, j + 1, res, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        helper(s, 0, res, curr);
        return res;
    }
};