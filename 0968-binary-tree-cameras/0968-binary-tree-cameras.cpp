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
    int minCameraCover(TreeNode* root) {
        
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