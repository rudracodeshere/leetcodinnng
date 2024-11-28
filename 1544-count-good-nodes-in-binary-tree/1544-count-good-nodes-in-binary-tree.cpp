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
    int util(TreeNode* root, int maxBefore) {
        if (root == NULL)
            return NULL;

        if (root->val >= maxBefore) {
            maxBefore = root->val;
            return 1 + util(root->left, maxBefore) +
                   util(root->right, maxBefore);
        }
        int leftCount = util(root->left, maxBefore);
        int rightCount = util(root->right, maxBefore);
        return leftCount + rightCount;
    }
    int goodNodes(TreeNode* root) { return util(root, INT_MIN); }
};