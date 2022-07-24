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
    
    void goodNodes(TreeNode *root, int maxx, int &cnt){
        
        if(root == NULL)
            return;
        
        
        int curr_max = maxx;
        
        if(root->val >= maxx){
            cnt++; //cout<<root->val<<endl;
            curr_max = root->val;
        }
        
        
        goodNodes(root->left, curr_max, cnt);
        goodNodes(root->right, curr_max, cnt);
        
        return ;
    }
    
    int goodNodes(TreeNode* root) {
        
        int maxx = -100000;
        int cnt =0;
        
        goodNodes(root, maxx, cnt);
        
        return cnt;
        
    }
};