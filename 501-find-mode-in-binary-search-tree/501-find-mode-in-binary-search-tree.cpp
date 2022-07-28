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
    
    void inOrder(TreeNode *root, int &number, int &count, int &maxFreq, vector<int> &ans){
        
        if(root== NULL) return;
        
        inOrder(root->left, number, count, maxFreq, ans);
        
        if(root->val == number)
            count++;
        else{
            count = 1;
            number = root->val;
        }
        
        
        
        if(count == maxFreq){
            ans.push_back(root->val);
        }else if(count > maxFreq){
            ans.clear();
            ans.push_back(root->val);
            maxFreq = count;
            number = root->val;
        }
        
        
        inOrder(root->right, number, count, maxFreq, ans);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        
        int number = -1e6;
        int count;
        int maxFreq=0;
        
        vector<int> ans;
        
        
        inOrder(root, number, count, maxFreq, ans);
        return ans;
    }
};