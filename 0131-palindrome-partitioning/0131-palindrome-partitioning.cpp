class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub;
        dfs(s, res, sub);
        return res;
    }
    void dfs(string s, vector<vector<string>>& res, vector<string> sub) {
        if (s.size() == 0) {
            res.push_back(sub);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            string temp = s.substr(0, i + 1);
            if (isPali(temp)) {
                sub.push_back(temp);
                dfs(s.substr(i + 1), res, sub);
                sub.pop_back();
            }
        }
    }
    bool isPali(string& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};