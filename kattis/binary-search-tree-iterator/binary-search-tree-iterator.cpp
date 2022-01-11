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
#include <vector>
using namespace std;

class BSTIterator {
public:
    int idx = 0;
    int n = 0;
    vector<int> arr;
    
    BSTIterator(TreeNode* root) {
        init(root);
        n = arr.size();
        idx = 0;
    }
    
    void init(TreeNode* root) {
        if (root == nullptr) return;
        init(root->left);
        arr.push_back(root->val);
        init(root->right);
    }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx < n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */