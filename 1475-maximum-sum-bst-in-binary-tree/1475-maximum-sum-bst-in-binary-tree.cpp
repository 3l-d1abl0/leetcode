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
int ans = 0;

vector<int> solve(TreeNode* root){
    if(!root)
    return {INT_MAX, INT_MIN, 0}; 

    int val = root->val;
    vector<int> left = solve(root -> left);
    vector<int> right = solve(root -> right);

    if(left.empty() || right.empty()) // IF Not BST
    return {};
    
    if(val > left[1] && val < right[0]){
        int sum = val + left[2] + right[2];
        ans = max(sum, ans);

        int minVal = min(val, left[0]);
        int maxVal = max(val, right[1]);
        
        return { minVal, maxVal, sum };
    }

    return {};  // not a BST
}

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};