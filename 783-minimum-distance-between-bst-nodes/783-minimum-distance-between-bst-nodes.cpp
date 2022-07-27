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
        
        if(root->left){
            minDiff(root->left, prev, diff);
        }
        
        if(prev != root->val)//avoid if there was no left subtree
        diff =  min(diff, abs(root->val-prev));
        
        
        prev = root->val;
        
        if(root->right){
            minDiff(root->right, prev, diff);
        }
        

        
    }
    
    int minDiffInBST(TreeNode* root) {
        
        int prev = root->val;
        int diff = INT_MAX;
        
        minDiff(root, prev, diff);
        
        return diff;
        
        
    }
};