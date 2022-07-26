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
    
    TreeNode *build(vector<int> &preorder, int &idx, int maxx){
        
        if(idx == preorder.size()  || preorder[idx] > maxx)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[idx]);
        idx++;
        root->left = build(preorder, idx, root->val);
        root->right = build(preorder, idx, maxx);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size() == 0)
            return NULL;
        
        int idx = 0;
        int maxx = INT_MAX;
        
        
        return build(preorder, idx, maxx);
    }
};