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
    
    int calcSum(TreeNode *root, long long int currentSum, int targetSum, unordered_map<long long int, int> &mp){
        
        if(root == NULL)
            return 0;
        
        int ans =0;
        currentSum += root->val;
        
        if(currentSum == targetSum)
            ans +=1;
        
        mp[currentSum]++;
        
        //check if targetSum -curretn sum exists
        if(mp.find(currentSum -targetSum) != mp.end()){
            
            if(targetSum ==0)
                ans += (mp[currentSum-targetSum]-1);
            else
                ans += mp[currentSum-targetSum];
        }
            
        
        
        
        
        ans +=calcSum(root->left, currentSum, targetSum, mp);
        ans +=calcSum(root->right, currentSum, targetSum, mp);
        
        mp[currentSum]--;
        
        
        return ans;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root== NULL)
            return 0;
        
        
        unordered_map<long long int, int> mp;
        
        long long int currentSum =0;
        
        
        return calcSum(root, currentSum, targetSum, mp);
        
    }
};