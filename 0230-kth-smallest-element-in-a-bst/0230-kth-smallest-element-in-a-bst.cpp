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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL)
            return NULL;
        int lc = countNodes(root->left);
        int rc = countNodes(root->right);
        if (lc >= k)
            return kthSmallest(root->left, k);
        if (lc + 1 == k)
            return root->val;
        else
            return kthSmallest(root->right, k - (lc + 1));
    }
};