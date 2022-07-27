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
    int fi(TreeNode *root, int parent){
        
        if(root== NULL) return -1;
        
        if(root->val != parent)
            return root->val;
        
        
        
        int lf = fi(root->left, root->val);
        int rt = fi(root->right, root->val);
        
        
        if(lf == -1)
            return rt;
        if(rt==-1)
            return lf;
        
        return min(lf, rt);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        
        int parent = root->val;
        
        return fi(root, parent);
    }
};