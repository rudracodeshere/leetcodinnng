class Solution {
public:
    map<char, string> mp = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> tmp = letterCombinations(digits.substr(1));
        vector<string> res;
        for (int i = 0; i < mp[digits[0]].size(); i++) {
            if (tmp.empty()) {
                string t = "";
                t.push_back(mp[digits[0]][i]);
                res.push_back(t);
            }
            for (auto s : tmp) {
                string t = mp[digits[0]][i] + s;
                res.push_back(t);
            }
        }
        return res;
    }
};