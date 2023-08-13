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
    
    /*
    1- Has/Installed Camera
    2- Needs Monitoring
    3 -Doesnt Need Monitoring/ Covered
    */
    
    int totalCam = 0;
    
    unordered_set<TreeNode* > covered;
    int minCameraCover(TreeNode* root) {
        
        
        //1. Method1
        //return method1(root);
        
        
        //2. Method2
        return method2(root);
        
        
        //3.
        
    }
    
    int method2(TreeNode *root){
        covered.insert(NULL);
        dfsMethod2(root, NULL);
        return totalCam;
    }
    
    
    void dfsMethod2(TreeNode *root, TreeNode *par){
        
        if(root==NULL)
            return;
        
        dfsMethod2(root->left, root);
        dfsMethod2(root->right, root);
        
        /*
            If any of the leaf is not covered - current node needs to be covered.
            If there is no parent and the current node is not covered - current node needs to be covered
            
            If the current node is covered, its parent and all child are covered by camera
        */
        
        if( covered.find(root->left) == covered.end() || 
            covered.find(root->right) == covered.end()||
          par==NULL && covered.find(root) == covered.end()){
            
            totalCam++;
            
            covered.insert(root);
            covered.insert(par);
            covered.insert(root->left);
            covered.insert(root->right);
            
        }
        
    }
    
    int method1(TreeNode *root){
        
        int status = dfs(root);
        
        //needs monitoring
        if(status==2)
            totalCam++;
        
        return totalCam;
        
    }
    
    int dfs(TreeNode* root){
        
        if(root==NULL)
            return 3;   //Doesn't Need Cam
        
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        
        //both child doesn't need Camera or Covered, child is either NULL or its child has camera
        if(left==3 && right==3){
            //both left and right doesn't need monitoring
            return 2;
        }

        
        if(left==2 || right ==2){
            //If anyone of the child needs monitoring, parnent has to have a camera
            totalCam++;
            return 1;
        }
        
        //At this point none of the child needs camera, either its 1 or 3
        if(left==1 || right ==1){
            //Child has camera, 
            return 3;
        }
        
        
        return 0;
    }
};