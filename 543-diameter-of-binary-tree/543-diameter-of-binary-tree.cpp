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
    
    int diameter(TreeNode* root, int &maxx){
        
        if(root==NULL)
            return 0;
        
        int lf = diameter(root->left, maxx);
        int rt = diameter(root->right, maxx);
        
        maxx = max(maxx, lf+rt+1);
        
        return max(lf, rt)+1;
        
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxx =0;
        diameter(root, maxx);
        
        return maxx-1;
    }
};