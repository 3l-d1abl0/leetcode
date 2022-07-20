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
    
    void preOrder(TreeNode* root, int &max_level, int &left_most,int lvl){
        
        if (root==NULL) return ;
        
        if(root->left == NULL && root->right == NULL){
            if(max_level < lvl){
                left_most = root->val;
                max_level = lvl;
            }
        }
        
        
        preOrder(root->left, max_level, left_most, lvl+1);
        preOrder(root->right, max_level, left_most, lvl+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        
        int max_level =-1;
        int left_most = root->val;
        
        
        preOrder(root, max_level, left_most, 0);
        
        return left_most;
    }
};