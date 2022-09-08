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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        if(root==NULL)
            return res;
        
        TreeNode *temp = root;
        stack<TreeNode *> st;
        bool flag = false;
        
        while(flag==false){
            
            while(temp !=NULL){
                st.push(temp);
                temp = temp->left;
            }
            
            if(!st.empty()){
                
                temp = st.top(); st.pop();
                res.push_back(temp->val);
                
                temp = temp->right;
                  
            }else{
                
                flag = true;
                
            }
            
            
            
        }//while
        
        return res;
        
    }
};