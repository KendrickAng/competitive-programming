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
    bool identical(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr and subRoot == nullptr) return true;
        if (root == nullptr and subRoot != nullptr) return false;
        if (root != nullptr and subRoot == nullptr) return false;
        return (root-> val == subRoot->val) and identical(root->left, subRoot->left) and identical(root->right, subRoot->right);
    }
    
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (identical(root, subRoot)) return true;
        if (root == nullptr) return subRoot == nullptr;
        bool left = helper(root->left, subRoot);
        bool right = helper(root->right, subRoot);
        return left || right;
    }

    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot);
    }
};