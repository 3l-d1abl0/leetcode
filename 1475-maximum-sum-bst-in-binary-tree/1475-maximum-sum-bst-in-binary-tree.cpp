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
    struct MetaData{
      int sum;  //total sum , if its a valid BST
      int minn; //left range limit
      int maxx; //right range limit

        //by default - invalid bst
        // MetaData(){
        //     sum = 0;
        //     minn = INT_MIN;
        //     maxx = INT_MAX;
        // }
    };
    
class Solution {
        private:
    //Every call returns
    
    MetaData getBst(TreeNode *root){
        
        if(root== NULL)//Valid BST
            return {0, INT_MAX, INT_MIN};
        
        //postOrder
        MetaData lf = getBst(root->left);
        MetaData rt = getBst(root->right);
        MetaData dt;
        
        //current node value falls withibn the range
        if(lf.maxx < root->val && root->val < rt.minn){
            
            dt.sum = lf.sum + rt.sum +root->val;
            dt.minn = min(root->val, lf.minn);
            dt.maxx = max(root->val, rt.maxx);
            //cout<<dt.sum<<" "<<dt.minn<<" "<<dt.maxx<<endl;
            
            //Track the max Sum seen So Far
            maxSum = max(dt.sum, maxSum);

            return dt;
            //cout<<"sum = "<<dt.sum<<" node="<<root->val<<endl;   
        }
        
        //IF the current value doesnt fall in range, either any of the subtree is not bst OR, the current val doesnt lie in range
        return {0, INT_MIN, INT_MAX}; //pass invalid limt + the max size valid bst found so far
        
    }
    
public:
    int maxSum = 0;
    int maxSumBST(TreeNode* root) {
        
        MetaData info = getBst(root);
        
        return maxSum;
    }
};