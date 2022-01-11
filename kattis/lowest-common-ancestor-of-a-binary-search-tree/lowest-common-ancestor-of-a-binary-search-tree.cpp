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
        TreeNode* ptr = root;
        if (p->val > q->val) swap(p, q);
        while (ptr->val < p->val || ptr->val > q->val) {
            if (ptr->val < p->val) ptr = ptr->right;
            else if (ptr->val > q->val) ptr = ptr->left;
        }
        return ptr;
    }
};