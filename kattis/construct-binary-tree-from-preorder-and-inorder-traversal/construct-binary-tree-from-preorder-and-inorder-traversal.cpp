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
    void print(vector<int> &v) {
        for (auto a: v) cout << a << " ";
        cout << endl;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        int root = preorder.front();
        TreeNode* ret = new TreeNode(root);
        
        // split inorder
        vector<int>::iterator it;
        for (it = inorder.begin(); it < inorder.end(); it++) {
            if (*it == root) break;
        }
        vector<int> iLeft(inorder.begin(), it);
        vector<int> iRight(it+1, inorder.end());

        // split preorder
        vector<int> pLeft(preorder.begin()+1, preorder.begin()+1+iLeft.size());
        vector<int> pRight(preorder.begin()+1+iLeft.size(), preorder.end());

        ret->left = buildTree(pLeft, iLeft);
        ret->right = buildTree(pRight, iRight);
        
        return ret;
    }
};