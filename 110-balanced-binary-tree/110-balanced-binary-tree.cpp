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
    
    int height(TreeNode *root, bool &bal){
        
        if(root==NULL)
            return 0;
        
        int lf = height(root->left, bal);
        int rt = height(root->right, bal);
        
        if(abs(lf-rt)>1)
            bal = false;
        
        return max(lf, rt)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        bool bal = true;
        height(root, bal);
        
        return bal;
    }
};