

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub;
        dfs(s, 0, res, sub);
        return res;
    }
    
    void dfs(string& s, int start, vector<vector<string>>& res, vector<string>& sub) {
        if (start == s.size()) {
            res.push_back(sub);
            return;
        }
        
        for (int end = start; end < s.size(); end++) {
            if (isPali(s, start, end)) {
                sub.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, res, sub);
                sub.pop_back();
            }
        }
    }
    
    bool isPali(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};