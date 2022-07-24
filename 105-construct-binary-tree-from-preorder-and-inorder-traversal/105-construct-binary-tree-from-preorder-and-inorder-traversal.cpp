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
    
    TreeNode* build(vector<int>& preorder, int l_pre, int r_pre, vector<int>& inorder, int l_in, int r_in, unordered_map<int, int> &inMap){
        
        if(l_pre >r_pre || l_in > r_in)
            return NULL;
        
        int rootEle = preorder[l_pre];
        
        int rootEleIdx = inMap[rootEle]; 
        int ns = rootEleIdx-l_in;

        TreeNode *root = new TreeNode(rootEle);
        root->left = build(preorder, l_pre+1, l_pre+ns, inorder, l_in, rootEleIdx-1, inMap);
        root->right = build(preorder, l_pre+ns+1, r_pre, inorder, rootEleIdx+1, r_in, inMap);
            
            
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  
        unordered_map<int, int>inMap;
        int l_pre =0, r_pre = preorder.size()-1;
        int l_in = 0, r_in = preorder.size()-1;
        
        for(int idx =0; idx < inorder.size(); idx++)
            inMap.insert({inorder[idx], idx});
        
        
        TreeNode * root = build(preorder, l_pre, r_pre, inorder, l_in, r_in, inMap);
        return root;
    }
};