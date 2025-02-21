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

    void solve(TreeNode *root, bool dir, int currLen, int &maxLength){

            if(root==NULL)
                return;

            maxLength = max(maxLength, currLen);

            solve(root->left, 0, dir==0?1:currLen+1, maxLength);
            solve(root->right, 1, dir==1?1:currLen+1, maxLength);

    }


    int longestZigZag(TreeNode* root) {
        

        int maxLength = 0;
        //0 - left, 1 - right
        solve(root->left, 0, 1, maxLength);
        solve(root->right, 1, 1, maxLength);

        return maxLength;
    }
};