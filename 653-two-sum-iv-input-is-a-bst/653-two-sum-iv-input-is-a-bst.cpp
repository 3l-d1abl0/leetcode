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
class Inorder{
    
    private:
    
        TreeNode *root;
        TreeNode *curr;
        bool forward;
        stack<TreeNode *>st;
        void pushAll(){
            
            while(curr!=NULL){
              
                st.push(curr);
                if(forward)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
        }
    
    public:
        
    Inorder(TreeNode *root, bool forward){
        this->root = root;
        this->curr = root;
        this->forward = forward;
        
        pushAll();
    }
    
    int next(){
        curr = st.top(); st.pop();
        int val = curr->val;
        
        if(forward)
            curr = curr->right;
        else
            curr = curr->left;
        
        pushAll();
        
        return val;
    }
    
};

class Solution {
public:
    
    bool usingSet(TreeNode *root, int k, unordered_set<int> &s){
        
        if(root==NULL) return false;
        
        if(s.find(k-root->val)!= s.end()) return true;
        
        s.insert(root->val);
        
        return usingSet(root->left, k, s) || usingSet(root->right, k, s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        //1. Using Sets
        //unordered_set<int> s;
        //return usingSet(root, k, s);
        
        //2. USing Inorder Iterator
        Inorder lf(root, true);   //forward iterator
        Inorder rt(root, false);  //backward iterator
        
        int l = lf.next();  int r = rt.next();
        
        while(l<r){
            
            if(l+r == k){
                return true;
            }else if(l+r > k){
                r = rt.next();
            }else{
                l = lf.next();
            }
            
        }
        
        return false;
    }
};