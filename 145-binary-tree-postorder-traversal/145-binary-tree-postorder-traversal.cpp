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
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        

    vector<int> res;
        
    if (root==NULL)
        return res;


        
    stack<TreeNode*> st;
    TreeNode *curr = root;
    TreeNode *prev = NULL;
    while (curr != NULL || !st.empty()){
        
        while(curr != NULL){
            
            st.push(curr);
            curr = curr->left;
        }
        
            curr = st.top();
            if (curr->right == NULL || curr->right == prev)
            {
                cout << curr->val << " ";
                res.push_back(curr->val);
                st.pop();
                prev = curr;
                curr = NULL;
            }
            else
                curr = curr->right;
        
    }

    
        return res;
    }
};