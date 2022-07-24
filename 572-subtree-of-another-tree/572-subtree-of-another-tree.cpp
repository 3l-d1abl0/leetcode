/**https://leetcode.com/lupusD/
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
    bool isSame(TreeNode *p, TreeNode *q){
        
        if(p== NULL && q== NULL)
            return true;
        
        if(p==NULL || q== NULL)
            return false;
            
        if(p->val != q->val)
            return false;
        
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
    
    
    bool check(TreeNode* root, TreeNode* subRoot){
            
        if(root == NULL)
            return false;
        
        bool stat = false;
        if(root->val == subRoot->val)
            stat = isSame(root, subRoot);
        
        if(stat) return true;
        
        bool lf = check(root->left, subRoot);
        
        if(lf) return lf;
        
        return check(root->right, subRoot);
    
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    
        return check(root, subRoot);
    }
    
    
};