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
    
    TreeNode* build(vector<int>& preorder, int preLeft, int preRight, unordered_map<int, int> &inMap, vector<int>& inorder, int inLeft, int inRight){
        
        //If the boundaries crosses each other
        if(preLeft > preRight || inLeft > inRight)
            return NULL;
        
        //root of the current SubTree
        int rootEle = preorder[preLeft];
        
        int rootEleIdx = inMap[rootEle]; 
        //number of element - on the left of node in Inorder
        int noe = rootEleIdx-inLeft;

        TreeNode *root = new TreeNode(rootEle);
        root->left = build(preorder, preLeft+1, preLeft+noe, inMap, inorder, inLeft, rootEleIdx-1);
        root->right = build(preorder, preLeft+noe+1, preRight, inMap, inorder, rootEleIdx+1, inRight);
            
            
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  
        unordered_map<int, int>inMap;   //Mapping of Node Val to idx
        for(int idx =0; idx < inorder.size(); idx++)
            inMap.insert({inorder[idx], idx});
        
        //Mark the boundaries for preOrder and inOrder
        int preLeft =0, preRight = preorder.size()-1;
        int inLeft = 0, inRight = inorder.size()-1;
        

        
        
        TreeNode * root = build(preorder, preLeft, preRight, inMap, inorder, inLeft, inRight);
        return root;
    }
};