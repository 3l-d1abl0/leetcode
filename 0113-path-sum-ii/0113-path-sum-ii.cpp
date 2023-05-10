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
    
    void checkPathSum(TreeNode *root, int currentSum, int targetSum, vector<int> path, vector<vector<int>> &allPath){
        
        if(root == NULL)
            return;
        
        currentSum = currentSum + root->val;
        //cout<<root->val<<" "<<currentSum<<endl;
        path.push_back(root->val);
        
        if(currentSum == targetSum && (root->left == NULL && root->right == NULL) ){
            /*for(int ele: path)
                cout<<ele<<" ";
            cout<<targetSum<<endl;*/
            
            allPath.push_back(path);
            return;
        }
        
        
        checkPathSum(root->left, currentSum, targetSum, path, allPath);
        checkPathSum(root->right, currentSum, targetSum, path, allPath);
        
        path.pop_back();
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        
        if(root == NULL)
            return {};
        
        vector<vector<int>> allPath;
        vector<int> path;
        
        int currentSum =0;
        
        checkPathSum(root, currentSum, targetSum, path, allPath);
        
        return allPath;
        
        
    }
};