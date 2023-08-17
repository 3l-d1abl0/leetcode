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
    
    int dfs(TreeNode *root, bool parent_choice, map< pair<TreeNode*, int >, int> &memo){
        
        if(root==NULL)
            return 0;
        
        
        if(memo.find( make_pair(root, parent_choice) ) != memo.end())
            return memo[{root, parent_choice}];
        
        int left_val=0, right_val=0;
        
        //parent was robber, this level need not be robbed
        if(parent_choice==true){
            left_val = dfs(root->left, false, memo);
            right_val = dfs(root->right, false, memo);
                
                
            return memo[make_pair(root, parent_choice)] = left_val+right_val+0;
            
        }else{
            
            //parent not robbed, rob this node OR not
            //Case 1 : Rob
            left_val = dfs(root->left, true, memo);
            right_val = dfs(root->right, true, memo);
            
            int case1Sum = left_val+right_val+root->val;
            
            //Case2 : don't Rob
            
            left_val = dfs(root->left, false, memo);
            right_val = dfs(root->right, false, memo);
            
            
            int case2Sum = left_val+right_val;
            
            
            
            /*if(case1Sum > case2Sum){
                cout<<"R== "<<root->val<<"  -> "<<case1Sum<<" "<<case2Sum<<endl;
                return case1Sum;    
            }else{
                return case2Sum;
            }*/
            
            return memo[make_pair(root, parent_choice)] = max(case1Sum, case2Sum);
        }
        
        return 0;
    }
    
    int rob(TreeNode* root) {
     
        map< pair<TreeNode*, int >, int> memo;
        
        return max(dfs(root->left, true, memo )+root->val+dfs(root->right, true, memo), dfs(root->left, false, memo)+0+dfs(root->right, false, memo));
    }
};