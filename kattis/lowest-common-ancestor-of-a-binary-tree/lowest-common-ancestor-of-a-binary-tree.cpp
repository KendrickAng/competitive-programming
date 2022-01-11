/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q)
            return root;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if (root->left != nullptr) 
            left = lowestCommonAncestor(root->left, p, q);
        if (root->right != nullptr) 
            right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root;
        else if (left != nullptr) return left;
        else return right;
    }
};