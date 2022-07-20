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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        //Single Queue approach
        
        if(root== NULL) return {};
        
        queue<TreeNode*> q;
        
        
        q.push(root);
        bool l2r = true;
        
        vector<vector<int>> zigzag;
            
        while(!q.empty()){
            
            int sz = q.size();
            vector<int> lvl(sz);
            
            for(int idx =0; idx<sz; idx++){
                
                TreeNode *node = q.front();
                q.pop();
                
                
                int index = l2r?idx: sz-1-idx;
                
                lvl[index] = node->val;
                
                if(node->left)
                    q.push(node->left);
                    
                if(node->right)
                    q.push(node->right);
            
            }
            
            zigzag.push_back(lvl);
            
            l2r = !l2r;
            
            
        }//while
        
        
        return zigzag;
        
    }
};