class Solution {
public:
    bool helper(int index, string s, unordered_set<string>& wordSet,
                vector<int>& memo) {
        if (index >= s.size()) {
            return true;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        for (int i = 1; index + i <= s.size(); i++) {
            string temp = s.substr(index, i);
            if (wordSet.find(temp) != wordSet.end()) {
                if (helper(index + i, s, wordSet, memo))
                    return memo[index] = true;
            }
        }
        return memo[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        vector<int> memo(s.length(), -1);
        for (auto& word : wordDict) {
            wordSet.insert(word);
        }
        return helper(0, s, wordSet, memo);
    }
};