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
    int distributeCoins(TreeNode* root) {
        
        
        int move =0;
        dfs(root, move);
        return move;
    }
    
    
    int dfs(TreeNode *root, int &move){
        
        if(root==NULL)
            return 0;   //0 excess or deficit;
        
        //will return excess or deficit, exces in + or deficit in -
        int left = dfs(root->left, move);   
        int right = dfs(root->right, move);
        
        move+= abs(left)+abs(right); //excess or deficit, coins need to be moved
        
        return root->val+left+right -1;    //1 coin is required at the node
    }
};