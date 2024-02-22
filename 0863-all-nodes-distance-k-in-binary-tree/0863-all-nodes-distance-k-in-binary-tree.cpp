/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void printkdistanceNodeDown(TreeNode* root, int k, vector<int> &ans){
        // Base Case
        if (root == NULL || k < 0) return;

        // If we reach a k distant node, print it
        if (k==0){
            ans.push_back(root->val);
            return;
        }

        // Recur for left and right subtrees
        printkdistanceNodeDown(root->left, k-1, ans);
        printkdistanceNodeDown(root->right, k-1, ans);
    }
 

    int printkdistanceNode(TreeNode* root, TreeNode* target , int k, vector<int> &ans){

        // Base Case 1: If tree is empty, return -1
        if (root == NULL) return -1;

        // If target is same as root. Use the downward function
        // to print all nodes at distance k in subtree rooted with
        // target or root
        if (root == target){
            printkdistanceNodeDown(root, k, ans);
            return 0;
        }

        // Recur for left subtree
        int dl = printkdistanceNode(root->left, target, k, ans);

        // Check if target node was found in left subtree
        if (dl != -1){
            // If root is at distance k from target, print root
            // Note that dl is Distance of root's 
            // left child from target
            if (dl + 1 == k)
                ans.push_back(root->val);

            // Else go to right subtree and print all k-dl-2 
            // distant nodes Note that the right child is 2 
            // edges away from left child
            else
                printkdistanceNodeDown(root->right, k-dl-2, ans);

            // Add 1 to the distance and return value for parent calls
            return 1 + dl;
        }

        // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
        // Note that we reach here only when node was 
        // not found in left subtree
        int dr = printkdistanceNode(root->right, target, k, ans);
        if (dr != -1){
            if (dr + 1 == k)
                ans.push_back(root->val);
            else
                printkdistanceNodeDown(root->left, k-dr-2, ans);
            return 1 + dr;
        }

        // If target was neither present in left
        // nor in right subtree
        return -1;

    }
    
    vector<int> method1(TreeNode* root, TreeNode* target, int k){
            vector<int> ans;
            printkdistanceNode(root, target , k, ans);
            return ans;
    }
    
    
    void getNodes(vector<int> &nodes, TreeNode* root, TreeNode* target, int k, unordered_set<TreeNode*> &visited, unordered_map<TreeNode*, TreeNode*> &parent){
        
        if(root==NULL)
            return;
        
        //already visited
        if(visited.find(root) != visited.end())
            return;
        
        visited.insert(root);
        
        if(k==0){
            nodes.push_back(root->val);
            return;
        }
        
        getNodes(nodes, root->left, target, k-1, visited, parent);
        getNodes(nodes, root->right, target, k-1, visited, parent);
        //parent
        getNodes(nodes, parent[root], target, k-1, visited, parent);
        
    }
    
    vector<int> method2(TreeNode* root, TreeNode* target, int k){
                
                unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        
        //Find Parent
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()){
            
            
            TreeNode *root = q.front();
            q.pop();
            
            if(root->left){
                q.push(root->left);
                parent[root->left] = root;
            }
            
            if(root->right){
                q.push(root->right);
                parent[root->right] = root;
            }
            
        }//while
        
        
        //Go to left right and parent, look for dist k;
        vector<int> nodes;
        unordered_set<TreeNode*> visited;
        getNodes(nodes, target, target, k, visited, parent);
        
        
        return nodes;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
                /*Method1
        Recursion: Finds the target. Goes down to k nodes below.
        sends 0 to parent. The parent which has the node
        sends remaining distance to its other branches.

        TC: O(N). No node will wil traversed at more than 2 Times.
        SC: O(h)
    */
            //return method1(root, target, k);
        
        
        /**/
        
             return method2(root, target, k);
            
            
    }
};