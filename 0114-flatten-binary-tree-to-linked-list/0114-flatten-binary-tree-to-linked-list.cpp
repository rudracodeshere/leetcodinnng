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
    TreeNode* util(TreeNode* root) {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
            return root;
        TreeNode* leftTail = util(root->left);
        TreeNode* rightTail = util(root->right);
        if (leftTail != NULL) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        return rightTail != NULL ? rightTail : leftTail;
    }

    void flatten(TreeNode* root) { util(root); }
};