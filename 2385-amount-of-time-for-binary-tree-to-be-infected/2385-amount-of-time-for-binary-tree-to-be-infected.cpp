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
    void setParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &p){
        
        if(root == NULL)
            return;
        
        if(root->left) p[root->left] = root;
        
        if(root->right)p[root->right] = root;
        
        setParent(root->left, p); setParent(root->right, p);
        
        return;
    }
    
    TreeNode *fetchTarget(TreeNode *root, int target){
        
        if(root==NULL)
            return NULL;
        
        if(root->val== target)
            return root;
        
        
        TreeNode *left = fetchTarget(root->left, target);
        
        if(left!=NULL)
            return left;
        
        return fetchTarget(root->right, target);
        
    }
    
    
    
    int amountOfTime(TreeNode* root, int start) {
        
        
        unordered_map<TreeNode *, bool> visited;
        unordered_map<TreeNode *, TreeNode *> parent;
        queue<TreeNode *> q;
        setParent(root, parent);
        
        
        int ctr = 0;
        
        
        TreeNode *target = fetchTarget(root, start);
        q.push(target);
        visited[target] = true;
        
        while(!q.empty()){
            
            int s = q.size();
            
            while(s--){
                TreeNode *curr = q.front(); q.pop();
                
                if(curr != root and !visited[parent[curr]]){
                    visited[parent[curr]] = true; q.push(parent[curr]);
                }
                
                if(curr->left and !visited[curr->left]){
                    visited[curr->left] = true; q.push(curr->left);
                }
                
                if(curr->right and !visited[curr->right]){
                    visited[curr->right] = true; q.push(curr->right);
                }
                
                
            }
            
            ctr++;
        }
     
        
        return ctr-1;
    }
        
    
};