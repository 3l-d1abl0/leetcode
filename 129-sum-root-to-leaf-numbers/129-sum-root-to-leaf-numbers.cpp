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
    
    int process(TreeNode *root, int num){
        
        if(root== NULL)
            return 0;
        
        num = num *10 +root->val;
        
        if(root->left == NULL && root->right == NULL)
            return num;
        
        int lf = process(root->left, num);
        int rt = process(root->right, num);
        
        return lf+rt;
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        
        return process(root, 0);
    }
};