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

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    TreeNode* trueRoot;
    int maxPath = -1;
    
    int dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return 0;
        // if (root->left == nullptr) return 1 + dfs(root->right);
        // if (root->right == nullptr) return 1 + dfs(root->left);
        int left = root->left == nullptr ? 0 : dfs(root->left) + 1;
        int right = root->right == nullptr ? 0 : dfs(root->right) + 1;
        if (root == trueRoot) {
            printf("%d %d\n", left, right);
        }
        maxPath = max(maxPath, left + right);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return 0;
        trueRoot = root;
        dfs(root);
        return maxPath ;
    }
};