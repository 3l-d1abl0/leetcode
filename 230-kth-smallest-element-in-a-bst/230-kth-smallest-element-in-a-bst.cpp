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
    
    int kth(TreeNode *root, int k, int &ctr){
        
        if(root == NULL)
            return -1;
        
        int lf = kth(root->left, k, ctr);
        
        if(lf!=-1) return lf;
        
        ctr++;
        if(k==ctr)
            return root->val;
        
        return kth(root->right, k, ctr);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int ctr =0;
        return kth(root, k, ctr);
    }
};