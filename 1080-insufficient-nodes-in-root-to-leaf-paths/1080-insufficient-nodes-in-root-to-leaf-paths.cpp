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
    
    bool prune(TreeNode *root, int limit, int sum){
            
        if(root->left == NULL && root->right == NULL){
            
            if(root->val+sum >= limit)
                return true;
            else
                return false;
        }
        
        
        bool lf = root->left ? prune(root->left, limit, sum+root->val): false;
        
        bool rt = root->right ? prune(root->right, limit, sum+root->val) : false;
        
      // cout<<root->val<<" "<<lf<<"::"<<rt<<endl;
        
        if(lf == false){
            //delete(root->left);
            root->left = NULL;
        }
        
        if(rt == false){
            //delete(root->right);
            root->right = NULL;
        }
            
        return lf | rt;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        bool stat = prune(root, limit, 0);

        if(stat == true)
            return root;
        else{
            //delete(root);
            return nullptr;
        }
    }
};