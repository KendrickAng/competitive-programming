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
    // min, max, isBST
    tuple<long,long,bool> dfs(TreeNode* root) {
        if (root == nullptr) return { 1e18, -1e18, true };
        
        long lMin, lMax, rMin, rMax;
        bool lisBST, risBST;
        
        tie(lMin, lMax, lisBST) = dfs(root->left);
        if (!lisBST) return { -1, -1, false };
        
        tie(rMin, rMax, risBST) = dfs(root->right);
        if (!risBST) return { -1, -1, false };
        
        long val = (long) root->val;
        bool isBST = (val > lMax) and (val < rMin);
        long minVal = min(val, min(lMin, rMin));
        long maxVal = max(val, max(lMax, rMax));
        
        return { minVal, maxVal, isBST };
    }
    
    bool isValidBST(TreeNode* root) {
        bool isBST;
        tie(ignore, ignore, isBST) = dfs(root);
        return isBST;
    }
};