/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (root==NULL)
            return "";
        
        queue<TreeNode *> q;        
        q.push(root);
        
        string str;
        
        while(!q.empty()){
            
            TreeNode *curr = q.front(); q.pop();
            
            if(curr == NULL)
                str.append("#,");
            else{
                str.append(to_string(curr->val)+",");
                
                q.push(curr->left);
                q.push(curr->right);
            }
            
            
        }//while
        
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        //cout<<data<<endl;
        
        if(data.size()==0) return NULL;
        
        stringstream s(data);
        string str;
        
        getline(s, str, ','); //, as delimeter str has the element
        
        TreeNode *root = new TreeNode(stoi(str));
        
        queue<TreeNode *> q;
        q.push(root);
        
        
        while(!q.empty()){
            
            
            TreeNode * curr = q.front(); q.pop();
            
            //Create its Left Child
            getline(s, str,',');
            if(str=="#")
                curr->left = NULL;
            else{
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            //Create it right child
            getline(s, str,',');
            if(str=="#")
                curr->right = NULL;
            else{
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));