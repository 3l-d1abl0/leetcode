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

    tuple<int, int, int> solve(TreeNode *root, int start){

        if(root==NULL)
            return {false, 0, 0};


        auto [lfFlag, lfHeight, lfAns] = solve(root->left, start);
        auto [rtFlag, rtHeight, rtAns] = solve(root->right, start);

        //current Node is Target Node
        if(root->val == start){
            return {true, 1, max(lfHeight, rtHeight)};
        }else if(lfFlag == true){
            return {true, 1+lfHeight, max(lfAns, lfHeight+rtHeight) };
        }else if(rtFlag == true){

            //cout<<true<<" "<<1+rtHeight<<" "<<max(rtAns, lfHeight+rtHeight)<<endl;
            return {true, 1+rtHeight, max(rtAns, lfHeight+rtHeight) };
        }
        
        //cout<<root->val<<"---"<<endl;
        return {false, 1+max(lfHeight, rtHeight), 0};
        
    }

    int amountOfTime(TreeNode* root, int start) {

        //1. DFS - post order find depth

        auto [flag, height, ans] = solve(root, start);


        return ans;     
    }
};