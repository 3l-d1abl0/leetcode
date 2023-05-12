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
    
    int calcDiameter(TreeNode *root, int &diameter){
        
        if(root==NULL)
            return 0;
        
        
        int lf = calcDiameter(root->left, diameter);
        int rt = calcDiameter(root->right, diameter);
        
        diameter = max(lf+rt+1, diameter);
        
        
        return max(lf, rt)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        int diameter =0;
        calcDiameter(root, diameter);
        
        return diameter-1;
    }
};