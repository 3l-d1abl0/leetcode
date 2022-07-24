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
    
    bool BST(TreeNode *root, long long minn, long long maxx){
        
        if(root==NULL)
            return true;
        
        if(root->val <=minn || root->val >=maxx)
            return false;
        
        return BST(root->left, minn, root->val) && BST(root->right, root->val, maxx);
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        
        if(root == NULL)
            return true;
        
        long long minn = INT_MIN, maxx = INT_MAX;
        maxx++; minn--;
        //cout<<minn<<" "<<maxx<<endl;
        return BST(root, minn, maxx);
    }
};