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
    
    void post(TreeNode *root){
        
        if(root==NULL)
            return ;
        
        post(root->left);
        post(root->right);
        
        
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        
    }
    TreeNode* invertTree(TreeNode* root) {
        
        post(root);
        return root;
    }
};