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
        
        //Prechecking of nodes value
        if(root==NULL || root==p || root==q)
            return root;
        
        
        TreeNode *lf = lowestCommonAncestor(root->left, p, q);
        
        TreeNode *rt = lowestCommonAncestor(root->right, p, q);
        
        if(lf!= NULL && rt!= NULL)
            return root;
        
        if(lf)
            return lf;
        else
            return rt;
        
    }
};