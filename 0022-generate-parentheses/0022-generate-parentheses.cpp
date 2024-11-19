class Solution {
public:
    void generateParenthesisUtil(int n, int open, int close,
                                 vector<string>& ans, string curr) {
        if (open == close && open == n) {
            ans.push_back(curr);
        }
        if (open > n || close == n)
            return;
        curr.push_back('(');
        generateParenthesisUtil(n, open + 1, close, ans, curr);
        curr.pop_back();
        if (close < open) {
            curr.push_back(')');
            generateParenthesisUtil(n, open, close + 1, ans, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans = {};
        generateParenthesisUtil(n, 0, 0, ans, "");
        return ans;
    }
};