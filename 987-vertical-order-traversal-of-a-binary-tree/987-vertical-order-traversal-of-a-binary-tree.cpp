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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        if(root==NULL) return {};
        
        map<int, map<int, vector<int>>> mp;
        queue<pair<int, TreeNode *>> q;
        
        q.push({0, root});

        pair<int, TreeNode *> pp;
        
        int row =0;
        while(!q.empty()){
            
            
            int sz = q.size();
            while(sz--){
                
                pp = q.front(); q.pop();

                int hd = pp.first;
                mp[hd][row].push_back(pp.second->val);

                if(pp.second->left)
                    q.push({hd-1, pp.second->left});

                if(pp.second->right)
                    q.push({hd+1, pp.second->right});
            }
         
            row++;

        }


        vector<vector<int>> ans;
        
        for(auto key: mp){

            vector<int> tmp;
            for(auto mpp: key.second){
                
                sort(mpp.second.begin(), mpp.second.end());    
                for(auto ele: mpp.second){
                    tmp.push_back(ele);
                }    
                
            }
            
            ans.push_back(tmp);
        }

        return ans;
        
    }
    
};