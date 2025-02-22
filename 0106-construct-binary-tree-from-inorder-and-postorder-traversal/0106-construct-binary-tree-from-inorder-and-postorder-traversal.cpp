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
    
        TreeNode* build(vector<int>& postorder, int l_post, int r_post, vector<int>& inorder, int l_in, int r_in, unordered_map<int, int> &inMap){
        
        //Valid Range
        if(l_post >r_post || l_in >r_in)
            return NULL;
        
        int rootEle = postorder[r_post];
        
        int rootEleIdx = inMap[rootEle]; 
            
        //noe on the left hand subtree of the node
        int noe = rootEleIdx-l_in;      // [l_in       ] rootEleIdx [.........r_in]

        TreeNode *root = new TreeNode(rootEle);
        root->left = build(postorder, l_post, l_post+noe-1, inorder, l_in, rootEleIdx-1, inMap);
        root->right = build(postorder, l_post+noe, r_post-1, inorder, rootEleIdx+1, r_in, inMap);
            
            
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int>inMap;
        for(int idx =0; idx < inorder.size(); idx++)
            inMap.insert({inorder[idx], idx});
        
        int l_post =0, r_post = postorder.size()-1;
        int l_in = 0, r_in = inorder.size()-1;
        
        
        
        TreeNode * root = build(postorder, l_post, r_post, inorder, l_in, r_in, inMap);
        return root;
    }
};