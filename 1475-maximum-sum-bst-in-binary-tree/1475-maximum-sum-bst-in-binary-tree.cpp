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
        private:
    
    struct MetaData{
      bool isBst;  
      int sum;
      int min;
      int max;
        MetaData(){
            isBst = true;
            sum =0;
            min = INT_MAX;
            max = INT_MIN;
        }
    };
    
    MetaData getBst(TreeNode *root, int &maxx){
        
        if(root== NULL) return MetaData ();
        
        /*if(root->left == NULL && root->right == NULL){
            return MetaData {true, root->val<0?0:root->val, root->val, root->val };
        }*/
        
        //postOrder
        
        MetaData lf = getBst(root->left, maxx);
        MetaData rt = getBst(root->right, maxx);
        
        MetaData dt;
        
        if(lf.isBst == true && rt.isBst == true && lf.max < root->val && root->val < rt.min){
            
            dt.sum = lf.sum + rt.sum +root->val;
            dt.min = min(root->val, lf.min);
            dt.max = max(root->val, rt.max);
            
            //cout<<"sum = "<<dt.sum<<" node="<<root->val<<endl;
            
        }else{ //left + node  + right is not a bst
            
            dt.isBst = false;
            dt.sum = max(lf.sum, rt.sum);//track the max Sum so far in the subtree
        }
        
        
        maxx = max(maxx, dt.sum);
        return dt;
        
    }
    
public:
    int maxSumBST(TreeNode* root) {
        
        int maxx =0;
        getBst(root, maxx);
        
        return maxx;
    }
};