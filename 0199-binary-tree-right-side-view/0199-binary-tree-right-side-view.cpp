/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void util(TreeNode* root, int& maxDepth, int currD) {
        if (root == NULL)
            return;
        if (currD > maxDepth) {
            res.push_back(root->val);
            maxDepth = currD;
        }
        util(root->right, maxDepth, currD + 1);
        util(root->left, maxDepth, currD + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        int maxDepth = INT_MIN;
        util(root, maxDepth, 0);
        return res;
    }
};