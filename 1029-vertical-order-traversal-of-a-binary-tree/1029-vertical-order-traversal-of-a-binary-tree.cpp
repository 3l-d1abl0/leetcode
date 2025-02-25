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

        /*
            For every column, the values in the individual row must be sorted
            Order:
            lower col to higher column
                lower roe to higher row
                    sort individual column value
        */
        
        
        if(root==NULL) return {};
        
        unordered_map<int, map<int, vector<int>>> mp; //col => {row, values}    
        queue<pair<int, TreeNode *>> q;
        
        q.push({0, root});  //col, node val
        pair<int, TreeNode *> pp;

        int minCol = INT_MAX;   //to track the min Col
        
        int row =0;
        while(!q.empty()){
            
            
            int sz = q.size();
            while(sz--){
                
                pp = q.front(); q.pop();

                int col = pp.first;
                minCol = min(minCol, col);

                mp[col][row].push_back(pp.second->val);

                if(pp.second->left)
                    q.push({col-1, pp.second->left});

                if(pp.second->right)
                    q.push({col+1, pp.second->right});
            }
         
            row++;

        }


        vector<vector<int>> ans;
        
        //for(auto key: mp){
        while(mp.find(minCol)!=mp.end()){

            vector<int> tmp;
            for(auto mpp: mp[minCol]){//go through every row
                
                sort(mpp.second.begin(), mpp.second.end());    
                for(auto ele: mpp.second){
                    tmp.push_back(ele);
                }    
                
            }
            
            ans.push_back(tmp);
            minCol++;
        }

        return ans;
        
    }
    
};