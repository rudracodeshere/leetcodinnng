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
    bool util(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return util(p->left, q->left) && util(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL)
            return true;
        if (root == NULL || subRoot == NULL)
            return false;
        bool a;
        if (root->val == subRoot->val) {
            a = util(root, subRoot);
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot) || a;
    }
};