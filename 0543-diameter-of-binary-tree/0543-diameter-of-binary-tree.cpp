/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> hd(TreeNode* root){
        if(root == NULL) return {0,0};
        auto l = hd(root->left);
        auto r = hd(root->right);

        return {1+max(l.first,r.first), max(l.first+r.first,max(l.second,r.second))};

    }
    int diameterOfBinaryTree(TreeNode* root) {
        return hd(root).second;
    }
};