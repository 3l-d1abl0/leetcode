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
    void right(TreeNode *root, vector<int> &path, int curr_depth, int &depth){
        if(root == NULL)
            return ;
        
        //cout<<root->val<<" "<<curr_depth<<" "<<depth<<endl;
        if(curr_depth >depth){
           depth = curr_depth;
           path.push_back(root->val);
        }
        
        
        if(root->right)
            right(root->right, path, curr_depth+1, depth);
        
        if(root->left)
            right(root->left, path, curr_depth+1, depth);
        
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> path;
        int depth =0;
        
        right(root, path, 1, depth);
        
        return path;
    }
};