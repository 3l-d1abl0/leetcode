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

    TreeNode* build(vector<int> &preorder, int l_pre, int r_pre, unordered_map<int, int> &postMap, vector<int> &postorder, int l_post, int r_post){

        //Valid Range
        if(l_pre > r_pre || l_post > r_post)
            return NULL;

        int rootEle = preorder[l_pre];
        TreeNode *root = new TreeNode(rootEle);
        if(l_pre+1 > r_pre)
            return root;
            
        cout<<"currentRoot: "<<rootEle<<" "<<l_pre<<" , "<<r_pre<<endl;

        int rootEleIdx = postMap[rootEle];

        //Find the next root of the left Sub tree
        int leftRootIdx = postMap[preorder[l_pre+1]];

        //noe in left
        int noe = leftRootIdx - l_post;

        
        //cout<<preorder[l_pre+1]<<" :: "<<l_pre+1<<" "<<l_pre+1+noe<<" _________ "<<l_post<<" "<<leftRootIdx<<endl;
        //cout<<preorder[l_pre+1+noe+1]<<" :: "<<l_pre+1+noe+1<<" "<<r_pre<<"_______________"<<leftRootIdx+1<<" "<<r_post<<endl;
        
        root->left = build(preorder, l_pre+1, l_pre+1+noe, postMap, postorder, l_post, leftRootIdx);
        root->right = build(preorder, l_pre+1+noe+1, r_pre , postMap, postorder, leftRootIdx+1, r_post);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        //mapping for node to idx
        unordered_map<int, int> postMap;
        for(int idx=0; idx<postorder.size(); idx++){
            postMap.insert({postorder[idx], idx});
        }

        int l_pre = 0, r_pre = preorder.size()-1;
        int l_post = 0, r_post = postorder.size()-1;

        TreeNode *root = build(preorder, l_pre, r_pre, postMap, postorder, l_post, r_post);


        return root;
    }
};