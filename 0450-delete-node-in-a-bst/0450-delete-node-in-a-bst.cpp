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
    TreeNode* deleteNode(TreeNode* root, int key) {
     
            
        if (root==NULL)
            return NULL;
            
            
        if (key < root->val){
            root->left = deleteNode(root->left, key);
        }else if (key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            
            //key == val
            
            //both child subtree exists
            if(root->left && root->right){
                
                TreeNode* childVal = findSuccessor(root->right);
                int toDelete = root->val;
                
                root->val = childVal->val;
                childVal->val = toDelete;
                
                root->right = deleteNode(root->right, toDelete);
            }else{
                return root->left ? root->left : root->right;
            }
            
        }
        
        
        return root;
    }
    
    TreeNode* findSuccessor(TreeNode* root){
        
        while(root->left != NULL)
            root =root->left;
        
        
        return root;
    }
};