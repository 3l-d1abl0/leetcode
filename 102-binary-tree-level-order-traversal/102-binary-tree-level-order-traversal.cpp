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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> lvl;
        queue<TreeNode *> q;
        
        if(root ==NULL) return lvl;
        
        q.push(root);
        
        int ctr=0;
        TreeNode *node;
        
        
        
        while(!q.empty()){
            
            ctr = q.size();
            vector<int> nodesInLvl;
            
            for(int i=1; i<=ctr; i++){
                    node = q.front(); q.pop();
                    nodesInLvl.push_back(node->val);
                    
                if(node->left!=NULL)
                    q.push(node->left);
                
                if(node->right!=NULL)
                    q.push(node->right);
                
                    
            }//for
            
            lvl.push_back(nodesInLvl);
        }//while
        
        return lvl;
    }
};