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
    
    void minDiff(TreeNode *root, int &prev, int &diff){
        
        if(root==NULL)
            return;
        
        //if(root->left){
            minDiff(root->left, prev, diff);
        //}
        
        if(prev != -1)//avoid if there was no left subtree for 1st node
        diff =  min(diff, abs(root->val-prev));
        
        
        prev = root->val;
        
        //if(root->right){
            minDiff(root->right, prev, diff);
        //}
        

        
    }
    
    int minDiffInBST(TreeNode* root) {
        
        int prev = -1;
        int diff = INT_MAX;
        
        minDiff(root, prev, diff);
        
        return diff;
        
        
    }
};