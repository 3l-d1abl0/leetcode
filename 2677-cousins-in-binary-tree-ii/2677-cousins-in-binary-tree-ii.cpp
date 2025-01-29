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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        /*
            For every level compute the sum and assign value of the level below
        */
        
        //root has no parents so no siblings
        root->val =0;
        
        
        queue<TreeNode *> q;
        q.push(root);
        
        
        while(!q.empty()){
            
            
            int sz = q.size();
            vector<TreeNode*> level;
            int levelSum =0;
            
            
            //calculate the level sum below
            while(sz--){
                
                TreeNode *node = q.front();
                q.pop();
                
                level.push_back(node);
                
                levelSum += (node->left?node->left->val:0)+(node->right?node->right->val:0);
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
            
            
            //For every node in level calculate levelSum - (sum of it s child)
            for(TreeNode *node: level){
                
                int sibSum = levelSum -( (node->left?node->left->val:0)+(node->right?node->right->val:0) );
               
                if(node->left)
                    node->left->val = sibSum;
                
                
                if(node->right)
                    node->right->val = sibSum;
                
            }
            
            
        }//while
        
        
        return root;
    }
};