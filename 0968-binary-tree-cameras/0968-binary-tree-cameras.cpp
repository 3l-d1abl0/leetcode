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
    
    map<pair<TreeNode*,pair<int,int>>, int> dp;
    
    int minCameraCover(TreeNode* root) {
        
        
        //1. Method1
        //return method1(root);
        
        
        //2. Method2
        //return method2(root);
        
        
        //3. Method3
        return method3(root);
        
    }
    
    /*===================Method3====================*/
    int method3(TreeNode *root){
        
        //solve(node, camera/no camera, parent camera/no)
        return min(solve(root, 1, 0), solve(root, 0, 0));
    }
    
    
    int solve(TreeNode* root, int  camera, int parentCamera){
        
        if(root==NULL){
            
            if(camera) return 1e7; //can't place a camera at NULL - return high value so an alternate way can be chosen
            else return 0;
        }
        
        
        if(root->left == NULL && root->right == NULL){  //leafnode
            
            if(camera){ //place a camera
                return 1;
            }else{  //camera not placed at leaf node
                
                if(parentCamera)    //parent already has camera
                    return 0;
                else
                    return 1e7;     //not possible - return high value so an alternate way can be chosen
            }
        }
        
        
        if( dp.find( {root, {camera, parentCamera}} ) != dp.end() ) 
            return dp[ {root, {camera, parentCamera} }];
            
        //if(dp.count({root, {camera, parentCamera}}) != 0 ) return dp[{root, {camera, parentCamera}}];
        
        if(camera){
            
            /* place a camera at curretn node
            from left node choose which option gives min ans (place camera/ do not place camera)
            from right node choose which option gives min ans (place camera/ do not place camera)
            pass parent camera as 1
            */
            
            return dp[{ root, {camera, parentCamera} }] = 1+ min( solve(root->left, 0, 1), solve(root->left, 1, 1) ) + min(solve(root->right, 0, 1), solve(root->right, 1, 1));
            
        }else{
            
            if(parentCamera){ 
                
                /* When parent has a camera, the current node is already covered
                   from left node choose which option gives min ans (place camera/ do not place camera)
                   from right node choose which option gives min ans (place camera/ do not place camera)
                   pass parent camera as 1
                */
                return dp[{ root, {camera, parentCamera} }] = min( solve(root->left, 0, 0), solve(root->left, 1, 0) ) + min(solve(root->right, 0, 0), solve(root->right, 1, 0));
                
            }else{
                
                /* condn: Parent does not have a camera, and no camera to be placed at current node
                    Case 1: Place a camera at left node + for right node which ever option gives min ans    
                    Case 2: Place a camera at right node + for left node which ever option gives min ans    
                */
                
                int case1 = solve(root->left, 1, 0) + min(solve(root->right, 0, 0), solve(root->right, 1, 0));
                
                int case2 = solve(root->right, 1, 0) + min(solve(root->left, 0, 0), solve(root->left, 1, 0));
                
                
                return dp[{ root, {camera, parentCamera} }] = min(case1, case2);
            }
            
        }
        
        
        return dp[{ root, {camera, parentCamera} }];
    }
    /*===================Method2====================*/
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
    
    
    
    
    /*===================Method1====================*/
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