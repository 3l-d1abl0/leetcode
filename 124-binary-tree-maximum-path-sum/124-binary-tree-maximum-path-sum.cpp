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
    
    int pathSum(TreeNode *root, int &maxx){
        
        if(root==NULL) return 0;   
        
        int lf = max(0, pathSum(root->left, maxx));
        int rt = max(0, pathSum(root->right, maxx));
        
        maxx = max(maxx, lf+rt+root->val);
        
        return max(lf,rt)+ root->val;
        
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        
        int maxx = INT_MIN;
        
        pathSum(root, maxx);
        
        return maxx;
    }
};