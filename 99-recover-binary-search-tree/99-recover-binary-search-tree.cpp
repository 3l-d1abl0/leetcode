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
    
    TreeNode *first;
    TreeNode *mid;
    TreeNode *last;
    
    TreeNode *prev;    
    
    void inOrder(TreeNode *root){
        
        if(root == NULL)
            return ;
        
        
        inOrder(root->left);
        
        //do ths stuff
        if(prev != NULL && root->val < prev->val){
            cout<<root->val<<endl;
            if(first == NULL){
                first = prev;
                mid = root;
            }else{
                last = root;
            }
            
            
        }
        
        prev = root;
        
        inOrder(root->right);
        
        
    }
    void recoverTree(TreeNode* root) {
        
        inOrder(root);
        
        
        if(last == NULL){
            swap(first->val,mid->val);
        }else{
            swap(first->val,last->val);
        }
        
    }
};